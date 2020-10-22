#ifndef FD_REUSE_H
#define FD_REUSE_H

#include <deque>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <unordered_map>

const int64_t DEFAULT_FD_CAP = 8;
// const int64_t DEFAULT_EXPIRE_SECOND = 10 * 60;
// const int64_t DEFAULT_CLEAN_SECOND = 10 * 60;
const int64_t DEFAULT_EXPIRE_SECOND = 1;
const int64_t DEFAULT_CLEAN_SECOND = 5;

class FdReuseData {
 public:
  FdReuseData();
  ~FdReuseData();
  int get();
  int put(int fd);
  int expired(int64_t expire_second = 0);
  std::string toString();

 private:
  mutable std::mutex mtx_;
  std::deque<int> fd_list_;
  int64_t timestamp_key_;
};

class FdReuse {
 public:
  FdReuse();
  ~FdReuse();
  int obtain_fd(const std::string& key);
  int obtain_fd(const std::string& ip, int port);
  int return_fd(const std::string& key, int fd);
  int return_fd(const std::string& ip, int port, int fd);
  int do_clean();
  std::string toString();
  static int connected_fd(int fd);

 private:
  mutable std::shared_mutex smtx_;
  std::unordered_map<std::string, FdReuseData*> fd_map_;
  int64_t timestamp_last_clean_;
};

static int clean_task(FdReuse& fd_reuse);

#endif  // FD_REUSE_H
