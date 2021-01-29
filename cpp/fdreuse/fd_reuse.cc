#include "fd_reuse.h"

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <vector>

#define PR_LOG_DEBUG(x) std::cout << x << std::endl;
#define PR_LOG_INFO(x) std::cout << x << std::endl;
#define PR_LOG_ERROR(x) std::cerr << x << std::endl;

namespace EggM {

static int CleanTask(FdReuse& fd_reuse);

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

int FdReuseData::Get() {
  std::unique_lock<std::mutex> lck(mtx_);
  if (fd_list_.empty()) {
    PR_LOG_INFO("FdReuseData::Get() fd_list_.empty()");
    return -1;
  }
  int fd = fd_list_.front();
  fd_list_.pop_front();
  timestamp_key_ = time(nullptr);
  return fd;
}

int FdReuseData::Put(int fd) {
  std::unique_lock<std::mutex> lck(mtx_);
  if (fd < 0) {
    PR_LOG_ERROR("FdReuseData::Put() fd=" << fd);
    return fd;
  }
  fd_list_.push_back(fd);
  timestamp_key_ = time(nullptr);
  return fd;
}

int FdReuseData::IsExpired(int64_t expire_second) {
  std::unique_lock<std::mutex> lck(mtx_);
  if (expire_second == 0) {
    expire_second = DEFAULT_EXPIRE_SECOND;
  }
  int64_t timeout_now = time(nullptr);
  return timestamp_key_ + expire_second < timeout_now ? 1 : 0;
}

std::string FdReuseData::ToString() {
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

int FdReuse::ObtainFd(const std::string& key) {
  // Key exist => read-lock. use {} avoid dead-lock
  {
    std::shared_lock<std::shared_mutex> lock(smtx_);
    if (fd_map_.find(key) != fd_map_.end()) {
      return fd_map_[key]->Get();
    }
  }
  // Key not exist => write-lock with double check
  std::unique_lock<std::shared_mutex> ulock(smtx_);
  if (fd_map_.find(key) != fd_map_.end()) {
    return fd_map_[key]->Get();
  }
  // If do need insert, first clean expired key(s), DoClean() func will create a detach thread
  int64_t timestamp_now = time(nullptr);
  if (timestamp_last_clean_ + DEFAULT_CLEAN_SECOND <= timestamp_now) {
    timestamp_last_clean_ = timestamp_now;
    try {
      std::thread t_clean_task(CleanTask, std::ref(*this));
      t_clean_task.detach();
    } catch (std::exception& e) {
      PR_LOG_ERROR("FdReuse::ObtainFd() Get exceotion:" << e.what());
    }
  }
  // Now we do insert
  FdReuseData* data =  new FdReuseData();
  fd_map_.insert(std::make_pair(key, data));
  return data->Get();
}

int FdReuse::ObtainFd(const std::string& ip, int port) {
  PR_LOG_INFO("FdReuse::ToString:\n" << ToString());
  return ObtainFd(ip + ":" + std::to_string(port));
}

int FdReuse::ReturnFd(const std::string& key, int fd) {
  // Read-lock, if key not exist, do nothing
  std::shared_lock<std::shared_mutex> lock(smtx_);
  if (fd_map_.find(key) == fd_map_.end()) {
    PR_LOG_ERROR("FdReuse::ReturnFd() ReturnFd() cannot find key=" << key);
    return -1;
  }
  return fd_map_[key]->Put(fd);
}

int FdReuse::ReturnFd(const std::string& ip, int port, int fd) {
  return ReturnFd(ip + ":" + std::to_string(port), fd);
}

int FdReuse::DoClean() {
  std::vector<std::string> expired_key_vec;
  // Check has any key expired => read-lock. use {} avoid dead-lock
  {
    std::shared_lock<std::shared_mutex> lock(smtx_);
    for (auto it = fd_map_.begin(); it != fd_map_.end(); it++) {
      if (it->second->IsExpired() == 1) {
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
    if (it->second->IsExpired() != 1) {
      continue;
    }
    delete it->second;
    it->second = nullptr;
    fd_map_.erase(key);
    erase_cnt++;
  }
  std::stringstream ss;
  ss << "expired_key_vec.size=" << expired_key_vec.size() << ",erase_cnt=" << erase_cnt
     << ",key_vec:";
  for (auto& key : expired_key_vec) {
    ss << key << ",";
  }
  ss << std::endl;
  PR_LOG_INFO(ss.str());
  return erase_cnt;
}

std::string FdReuse::ToString() {
  std::unique_lock<std::shared_mutex> ulock(smtx_);
  std::stringstream ss;
  int idx = 0;
  for (auto it = fd_map_.begin(); it != fd_map_.end(); it++) {
    ss << "idx=" << idx << ",key=" << it->first << ",FdReuseData:" << it->second->ToString();
    idx++;
  }
  return ss.str();
}

int FdReuse::IsConnected(int fd) {
  struct tcp_info info;
  size_t len = sizeof(info);
  getsockopt(fd, IPPROTO_TCP, TCP_INFO, &info, (socklen_t *)&len);
  return info.tcpi_state == TCP_ESTABLISHED ? 1 : 0;
}

int FdReuse::ConnectWithSelect(const std::string& ip, int port, int64_t timeout_ms) {
  struct sockaddr_in addr_in;
  memset(&addr_in, 0, sizeof(addr_in));
  addr_in.sin_family = AF_INET;
  addr_in.sin_port = htons(port);
  addr_in.sin_addr.s_addr = inet_addr(ip.c_str());

  int fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, IPPROTO_TCP);
  if (fd < 0) {
    PR_LOG_ERROR("socket() fail, ret fd=" << fd);
    return -10;
  }

  int ret = 0;
  ret = connect(fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
  if (ret == 0) {
    PR_LOG_INFO("socket connect succeed immediately");
    return fd;
  }
  if (ret != 0 && errno != EINPROGRESS) {
    PR_LOG_ERROR("connect() error, ret=" << ret << "errmsg=" << strerror(errno));
    close(fd);
    return -20;
  }
  PR_LOG_INFO("connect() ret=" << ret << ",errno=" << errno << ",errmsg=" << strerror(errno));

  fd_set rfds, wfds;
  FD_ZERO(&rfds);
  FD_ZERO(&wfds);
  FD_SET(fd, &rfds);
  FD_SET(fd, &wfds);
  struct timeval tv_conn = {0, timeout_ms * 1000};
  ret = select(fd + 1, &rfds, &wfds, NULL, &tv_conn);

  // ** error, select error
  if (ret < 0) {
    PR_LOG_ERROR("select() fail,ret=" << ret << ",errno=" << errno
                                      << ",errmsg=" << strerror(errno));
    close(fd);
    return -30;
  }

  // ** error, select timeout
  if (ret == 0) {
    PR_LOG_ERROR("select() timeout,errno=" << errno << ",errmsg=" << strerror(errno));
    close(fd);
    return -31;
  }

  // ** success
  if (ret == 1 && FD_ISSET(fd, &wfds)) {
    int flags = fcntl(fd, F_GETFL, 0);
    PR_LOG_INFO("[1]flags=" << flags);
    if (flags < 0) {
      PR_LOG_ERROR("fcntl get flag fail,ret flags=" << flags);
      close(fd);
      return -32;
    }
    flags &= ~O_NONBLOCK;
    flags = fcntl(fd, F_SETFL, flags);
    PR_LOG_INFO("[2]flags=" << flags);
    if (flags < 0) {
      PR_LOG_ERROR("fcntl set noblock fail,ret flags=" << flags);
      close(fd);
      return -33;
    }

    PR_LOG_INFO("connect_select succeed and reset to block,fd=" << fd);
    return fd;
  }

  // ** error, unknown
  PR_LOG_ERROR("connect unknown error occur");
  close(fd);
  return -50;
}

int FdReuse::ConnectWithPoll(const std::string& ip, int port, int64_t timeout_ms) {
  struct sockaddr_in addr_in;
  memset(&addr_in, 0, sizeof(addr_in));
  addr_in.sin_family = AF_INET;
  addr_in.sin_port = htons(port);
  addr_in.sin_addr.s_addr = inet_addr(ip.c_str());

  int fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, IPPROTO_TCP);
  if (fd < 0) {
    PR_LOG_ERROR("socket() fail, ret fd=" << fd);
    return -10;
  }

  int ret = 0;
  ret = connect(fd, (struct sockaddr*)&addr_in, sizeof(addr_in));

  if (errno == EINPROGRESS) {
    struct pollfd wfd[1];
    wfd[0].fd = fd;
    wfd[0].events = POLLOUT;

    if ((ret = poll(wfd, 1, timeout_ms)) == -1) {
      PR_LOG_ERROR("poll() error,ret=" << ret << ",errmsg=" << strerror(errno));
      close(fd);
      return -20;
    } else if (ret == 0) {
      PR_LOG_ERROR("poll() timeout,timeout_ms=" << timeout_ms << ",errmsg=" << strerror(errno));
      close(fd);
      return -30;
    }

    // ** reset to blocking
    u_long mode = 0;
    if (ioctl(fd, FIONBIO, &mode) == -1) {
      PR_LOG_ERROR("ioctl() set to blocking error, ret=-1");
      close(fd);
      return -40;
    }

    PR_LOG_INFO("connect_poll succeed and reset to block,fd=" << fd);
    return fd;
  }

  // ** error, unknown
  PR_LOG_ERROR("connect unknown error occur");
  close(fd);
  return -50;
}

int FdReuse::ConnectWithEpoll(const std::string& ip, int port, int64_t timeout_ms) {
  int ret = 0;

  struct sockaddr_in addr_in;
  memset(&addr_in, 0, sizeof(addr_in));
  addr_in.sin_family = AF_INET;
  addr_in.sin_port = htons(port);
  addr_in.sin_addr.s_addr = inet_addr(ip.c_str());

  int fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, IPPROTO_TCP);
  if (fd < 0) {
    PR_LOG_ERROR("socket() fail, ret fd=" << fd);
    return -10;
  }
  
  ret = connect(fd, (struct sockaddr*)&addr_in, sizeof(addr_in));
  if (ret == 0) {
    PR_LOG_INFO("socket connect succeed immediately");
    return fd;
  }

  if (errno == EINPROGRESS) {
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLOUT;

    int epfd = epoll_create1(0);
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
    if (ret != 0) {
      PR_LOG_ERROR("epoll_ctl() ADD ret=" << ret << ",errmsg=" << strerror(errno));
      close(epfd);
      close(fd);
      return -15;
    }

    struct epoll_event event_vec[1];
    int n = epoll_wait(epfd, event_vec, 1, timeout_ms);
    if (n != 1) {
      PR_LOG_ERROR("epoll_wait() ret=" << n);
      close(epfd);
      close(fd);
      return -20;
    }
    if (event_vec[0].data.fd != fd) {
      PR_LOG_ERROR("event_vec[0].data.fd=" << event_vec[0].data.fd << ", not equal to fd=" << fd);
      close(epfd);
      close(fd);
      return -30;
    }
    if ((event_vec[0].events & EPOLLOUT) == 0) {
      PR_LOG_ERROR("event_vec[0].events=" << event_vec[0].events);
      close(epfd);
      close(fd);
      return -35;
    }

    // ** reset to blocking
    u_long mode = 0;
    if (ioctl(fd, FIONBIO, &mode) == -1) {
      PR_LOG_ERROR("ioctl() set to blocking error, ret=-1");
      close(epfd);
      close(fd);
      return -40;
    }

    ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &event);
    if (ret != 0) {
      PR_LOG_ERROR("epoll_ctl() DEL ret=" << ret << ",errmsg=" << strerror(errno));
      close(epfd);
      close(fd);
      return -45;
    }

    PR_LOG_INFO("connect_epoll succeed and reset to block,fd=" << fd);
    close(epfd);
    return fd;
  }

  // ** error, unknown
  PR_LOG_ERROR("connect_epoll unknown error occur");
  close(fd);
  return -50;
}

static int CleanTask(FdReuse& fd_reuse) {
  return fd_reuse.DoClean();
}

} // namespace EggM