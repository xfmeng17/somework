#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <unordered_map>
#include <set>
#include <mutex>
#include <math.h>
#include <thread>
#include <chrono>
#include <ctime>

#define REPEATE_BEGIN(name, times)                 \
  {                                                \
    const char* timer_name = name;                 \
    auto start = std::chrono::steady_clock::now(); \
    uint32_t repeate = times;                      \
    for (uint32_t i = 0; i < repeate; i++) {

#define REPEATE_END()                                                                           \
  }                                                                                             \
  auto end = std::chrono::steady_clock::now();                                                  \
  auto chrone_nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); \
  std::cout << timer_name << " repeate " << repeate << " times, total time:" << chrone_nsec          \
       << " ns, each repeate time:" << chrone_nsec / repeate << " ns." << std::endl;                 \
  }

static const int REPEATE_NUM = 1000000;
static std::mutex mtx;

static void dummy_run(int repeated) {
  uint64_t a = 1610612741;
  uint64_t b = 805306457;
  for (int i = 0; i < repeated; i++) {
    mtx.lock();
    a = sqrt(a * b / 201326611 + 1);
    a = sqrt(a * b / 100663319 + 1);
    a = sqrt(a * b / 50331653 + 1);
    a = sqrt(a * b / 25165843 + 1);
    mtx.unlock();
  }
  return;
}

int main() {
  for (int cnt = 1; cnt <= 9; cnt++) {
    auto start = std::chrono::steady_clock::now();
    std::thread th_vec[cnt];
    for (int i = 0; i < cnt; i++) {
      th_vec[i] = std::thread(dummy_run, REPEATE_NUM);
    }
    for (auto& t : th_vec) {
      t.join();
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << ">> thread=" << cnt << ", dummy_run cost(ns)=" << elapsed / REPEATE_NUM << std::endl;
    // std::cout << ">> thread=" << cnt << ", dummy_run cost(ns)=" << elapsed << std::endl;
  }
}