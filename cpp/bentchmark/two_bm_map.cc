#include <array>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include <benchmark/benchmark.h>

using namespace std;

static map<int, int> dummy;

void foo(benchmark::State& state) {
  for (auto _ : state) {
    for (int i = 0; i < 10000; i++) {
      dummy.insert({1, 1});
    }
  }
}
void bar(benchmark::State& state) {
  for (auto _ : state) {
    for (int i = 0; i < 10000; i++) {
      dummy.insert({1, 1});
    }
  }
}

BENCHMARK(foo);
BENCHMARK(bar);

BENCHMARK_MAIN();
