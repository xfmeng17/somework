#ifndef FD_REUSE_H
#define FD_REUSE_H

#include <string.h>

#include <deque>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <unordered_map>

namespace EggM {

const int64_t DEFAULT_FD_CAP = 8;
const int64_t DEFAULT_EXPIRE_SECOND = 10 * 60;
const int64_t DEFAULT_CLEAN_SECOND = 10 * 60;
// const int64_t DEFAULT_EXPIRE_SECOND = 1;
// const int64_t DEFAULT_CLEAN_SECOND = 5;

class FdReuseData {
 public:
  FdReuseData();
  ~FdReuseData();
  int Get();
  int Put(int fd);
  int IsExpired(int64_t expire_second = 0);
  std::string ToString();

 private:
  mutable std::mutex mtx_;
  std::deque<int> fd_list_;
  int64_t timestamp_key_;
};

class FdReuse {
 public:
  FdReuse();
  ~FdReuse();
  int ObtainFd(const std::string& key);
  int ObtainFd(const std::string& ip, int port);
  int ReturnFd(const std::string& key, int fd);
  int ReturnFd(const std::string& ip, int port, int fd);
  int DoClean();
  std::string ToString();

  static int ConnectWithSelect(const std::string& ip, int port, int64_t timeout_ms);
  static int ConnectWithPoll(const std::string& ip, int port, int64_t timeout_ms);
  static int ConnectWithEpoll(const std::string& ip, int port, int64_t timeout_ms);
  static int IsConnected(int fd);

 private:
  mutable std::shared_mutex smtx_;
  std::unordered_map<std::string, FdReuseData*> fd_map_;
  int64_t timestamp_last_clean_;
};

} // namespace EggM

#endif  // FD_REUSE_H
