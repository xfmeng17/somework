#include "fd_reuse.h"

#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <vector>

#define PR_LOG_DEBUG(x) std::cout << x << std::endl;
#define PR_LOG_INFO(x) std::cout << x << std::endl;
#define PR_LOG_ERROR(x) std::cerr << x << std::endl;

FdReuseData::FdReuseData() {
  fd_list_.clear();
  timestamp_key_ = time(nullptr);
}

FdReuseData::~FdReuseData() {
  for (auto& fd : fd_list_) {
    // if (fcntl(fd, F_GETFD) != -1 || errno != EBADF) {
    //   PR_LOG_INFO("FdReuseData::~FdReuseData() close fd=" << fd);
    //   close(fd);
    // }

    // Just close(fd) directly
    close(fd);
  }
  fd_list_.clear();
}

int FdReuseData::get() {
  std::unique_lock<std::mutex> lck(mtx_);
  if (fd_list_.empty()) {
    PR_LOG_INFO("FdReuseData::get() fd_list_.empty()");
    return -1;
  }
  int fd = fd_list_.front();
  fd_list_.pop_front();
  timestamp_key_ = time(nullptr);
  return fd;
}

int FdReuseData::put(int fd) {
  std::unique_lock<std::mutex> lck(mtx_);
  if (fd < 0) {
    PR_LOG_ERROR("FdReuseData::put() fd=" << fd);
    return fd;
  }
  fd_list_.push_front(fd);
  timestamp_key_ = time(nullptr);
  return fd;
}

int FdReuseData::expired(int64_t expire_second) {
  std::unique_lock<std::mutex> lck(mtx_);
  if (expire_second == 0) {
    expire_second = DEFAULT_EXPIRE_SECOND;
  }
  int64_t timeout_now = time(nullptr);
  return timestamp_key_ + expire_second < timeout_now ? 1 : 0;
}

std::string FdReuseData::toString() {
  std::unique_lock<std::mutex> lck(mtx_);
  std::stringstream ss;
  int idx = 0;
  ss << "timestamp_key_=" << timestamp_key_ << ",fd_list:";
  for (auto it = fd_list_.begin(); it != fd_list_.end(); it++) {
    ss << *it << ",";
    idx++;
  }
  ss << "cnt=" << idx << std::endl;
  return ss.str();
}

FdReuse::FdReuse() {}
FdReuse::~FdReuse() {
  for (auto it = fd_map_.begin(); it != fd_map_.end(); it++) {
    if (it->second != nullptr) {
      delete it->second;
      it->second = nullptr;
    }
  }
  fd_map_.clear();
}

int FdReuse::obtain_fd(const std::string& key) {
  // Key exist => read-lock. use {} avoid dead-lock
  {
    std::shared_lock<std::shared_mutex> lock(smtx_);
    if (fd_map_.find(key) != fd_map_.end()) {
      return fd_map_[key]->get();
    }
  }
  // Key not exist => write-lock with double check
  std::unique_lock<std::shared_mutex> ulock(smtx_);
  if (fd_map_.find(key) != fd_map_.end()) {
    return fd_map_[key]->get();
  }
  // If do need insert, first clean expired key(s), do_clean() func will create
  // a detach thread
  int64_t timestamp_now = time(nullptr);
  if (timestamp_last_clean_ + DEFAULT_CLEAN_SECOND <= timestamp_now) {
    timestamp_last_clean_ = timestamp_now;
    try {
      std::thread t_clean_task(clean_task, std::ref(*this));
      t_clean_task.detach();
    } catch (std::exception& e) {
      PR_LOG_ERROR("FdReuse::obtain_fd() get exceotion:" << e.what());
    }
  }
  // Now we do insert
  FdReuseData* data = new FdReuseData();
  fd_map_.insert(std::make_pair(key, data));
  return data->get();
}

int FdReuse::obtain_fd(const std::string& ip, int port) {
  PR_LOG_DEBUG("FdReuse::toString:\n" << toString());
  return obtain_fd(ip + ":" + std::to_string(port));
}

int FdReuse::return_fd(const std::string& key, int fd) {
  // Read-lock, if key not exist, do nothing
  std::shared_lock<std::shared_mutex> lock(smtx_);
  if (fd_map_.find(key) == fd_map_.end()) {
    PR_LOG_ERROR("FdReuse::return_fd() return_fd() cannot find key=" << key);
    return -1;
  }
  return fd_map_[key]->put(fd);
}

int FdReuse::return_fd(const std::string& ip, int port, int fd) {
  return return_fd(ip + ":" + std::to_string(port), fd);
}

int FdReuse::do_clean() {
  std::vector<std::string> expired_key_vec;
  // Check has any key expired => read-lock. use {} avoid dead-lock
  {
    std::shared_lock<std::shared_mutex> lock(smtx_);
    for (auto it = fd_map_.begin(); it != fd_map_.end(); it++) {
      if (it->second->expired() == 1) {
        expired_key_vec.emplace_back(it->first);
      }
    }
  }
  // No key expired, return directly
  if (expired_key_vec.empty()) {
    return 0;
  }

  // Has key expired => write-lock with double check
  std::unique_lock<std::shared_mutex> ulock(smtx_);
  int erase_cnt = 0;
  for (auto& key : expired_key_vec) {
    auto it = fd_map_.find(key);
    if (it == fd_map_.end()) {
      continue;
    }
    if (it->second->expired() != 1) {
      continue;
    }
    delete it->second;
    it->second = nullptr;
    fd_map_.erase(key);
    erase_cnt++;
  }
  std::stringstream ss;
  ss << "expired_key_vec.size=" << expired_key_vec.size()
     << ",erase_cnt=" << erase_cnt << ",key_vec:";
  for (auto& key : expired_key_vec) {
    ss << key << ",";
  }
  ss << std::endl;
  PR_LOG_INFO(ss.str());
  return erase_cnt;
}

std::string FdReuse::toString() {
  std::unique_lock<std::shared_mutex> ulock(smtx_);
  std::stringstream ss;
  int idx = 0;
  for (auto it = fd_map_.begin(); it != fd_map_.end(); it++) {
    ss << "idx=" << idx << ",key=" << it->first
       << ",FdReuseData:" << it->second->toString();
    idx++;
  }
  return ss.str();
}

int FdReuse::connected_fd(int fd) {
  struct tcp_info info;
  size_t len = sizeof(info);
  getsockopt(fd, IPPROTO_TCP, TCP_INFO, &info, (socklen_t*)&len);
  return info.tcpi_state == TCP_ESTABLISHED ? 1 : 0;
}

static int clean_task(FdReuse& fd_reuse) { return fd_reuse.do_clean(); }
