#include "fd_reuse.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

void Worker(FdReuse& fd_reuse, int num) {
  srand((unsigned)time(nullptr));
  std::ofstream os_write("outlog." + std::to_string(num), std::ofstream::trunc);
  for (int i = 0; i < num; i++) {
    os_write << "Worker num=" << num << ", i=" << i << std::endl;
    std::string key = "key_" + std::to_string(rand() % 50);
    int fd = fd_reuse.obtain_fd(key);
    os_write << "num=" << num << ", key=" << key << ", obtain_fd=" << fd
             << std::endl;

    if (fd <= 0) {
      // fd = rand() % 100 + (num - 100);
      fd = open("outlog.fdopen", O_CREAT | O_RDWR, 0666);
      os_write << "num=" << num << ", key=" << key << ", reset_fd=" << fd
               << std::endl;
    }

    fd = fd_reuse.return_fd(key, fd);
    os_write << "num=" << num << ", key=" << key << ", return_fd=" << fd
             << std::endl;

    usleep(1000000);
  }
  os_write.close();
  return;
}

int main() {
  FdReuse fd_reuse;
  std::cout << "#1: fd_reuse: " << fd_reuse.toString() << std::endl;
  std::vector<std::thread> thread_vec;
  // thread_vec.reserve(16);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 200);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 300);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 400);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 500);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 600);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 700);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 800);
  thread_vec.emplace_back(&Worker, std::ref(fd_reuse), 900);

  for (std::thread& t : thread_vec) {
    t.join();
  }
  std::cout << "#2: fd_reuse: " << fd_reuse.toString() << std::endl;

  return 0;
}
