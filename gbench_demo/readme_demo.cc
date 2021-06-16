// https://github.com/google/benchmark/blob/main/test/basic_test.cc 参考的这个
// https://groups.google.com/g/benchmark-discuss/search?q=CPU%20Time 检索 CPU Time
// https://groups.google.com/g/benchmark-discuss/c/jF6j81HjabM/m/7kUKRBP5AgAJ 为啥Time 会小于
// CPU？因为多线程的时候Time会除以线程数

// 参考下文API文档
// https://gerrit.pixelexperience.org/plugins/gitiles/external_libcxx/+/d9b9ef75a8ada5f9caaf2f4984bfb8094ade2590/utils/google-benchmark/include/benchmark/benchmark_api.h

// benchmark README
// https://github.com/google/benchmark#output-formats

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <mutex>
#include <random>
#include <set>
#include <string>
#include <unordered_map>

#include "benchmark/benchmark.h"

#define BASIC_BENCHMARK_TEST(x) BENCHMARK(x)->Arg(8)->Arg(512)->Arg(8192)

static std::mutex mtx;
static std::map<std::string, std::string> map;

static std::string str_rand(int length) {
  char tmp;
  std::string buffer;
  std::random_device rd;
  std::default_random_engine random(rd());
  for (int i = 0; i < length; i++) {
    tmp = random() % 36;
    if (tmp < 10) {
      tmp += '0';
    } else {
      tmp -= 10;
      tmp += 'A';
    }
    buffer += tmp;
  }
  return buffer;
}

static void dummy_run(int repeated = 1000000) {
  uint64_t a = 1610612741;
  uint64_t b = 805306457;
  // for (int i = 0; i < repeated; i++) {
  mtx.lock();
  a = sqrt(a * b / 201326611 + 1);
  a = sqrt(a * b / 100663319 + 1);
  a = sqrt(a * b / 50331653 + 1);
  a = sqrt(a * b / 25165843 + 1);
  mtx.unlock();
  // }
  return;
}

void BM_empty(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(state.iterations());
  }
}
BENCHMARK(BM_empty);
BENCHMARK(BM_empty)->ThreadPerCpu();

void BM_my01(benchmark::State& state) {
  for (auto _ : state) {
    dummy_run();
  }
}
BENCHMARK(BM_my01);
BENCHMARK(BM_my01)->DenseThreadRange(1, 9, 1);

void BM_spin_empty(benchmark::State& state) {
  for (auto _ : state) {
    mtx.lock();
    for (int x = 0; x < state.range(0); ++x) {
      benchmark::DoNotOptimize(x);
    }
    mtx.unlock();
  }
}
BASIC_BENCHMARK_TEST(BM_spin_empty);
BASIC_BENCHMARK_TEST(BM_spin_empty)->ThreadPerCpu();

BENCHMARK_MAIN();
