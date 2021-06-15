#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <unordered_map>

#include "benchmark/benchmark.h"

static const int KEY_NUM = 1000;
static const int KEY_LEN = 20;

static std::map<std::string, std::string> tree_str_map;
static std::unordered_map<std::string, std::string> hash_str_map;
static std::vector<std::string> key_str_vec;

static std::map<uint64_t, std::string> tree_int_map;
static std::unordered_map<uint64_t, std::string> hash_int_map;
static std::vector<uint64_t> key_int_vec;

static std::string str_rand(int length) {  // length: 产生字符串的长度
  char tmp;                                // tmp: 暂存一个随机数
  std::string buffer;                      // buffer: 保存返回值
  // 下面这两行比较重要:
  std::random_device rd;                    // 产生一个 std::random_device 对象 rd
  std::default_random_engine random(rd());  // 用 rd 初始化一个随机数发生器 random
  for (int i = 0; i < length; i++) {
    tmp = random() % 36;  // 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
    if (tmp < 10) {       // 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
      tmp += '0';
    } else {  // 否则，变换成一个大写字母的 ASCII
      tmp -= 10;
      tmp += 'A';
    }
    buffer += tmp;
  }
  return buffer;
}

class SetupMap {
  SetupMap() {
    for (int i = 0; i < KEY_NUM; i++) {
      std::string key = str_rand(KEY_LEN);
      std::string val = str_rand(KEY_LEN);
      tree_str_map[key] = val;
      hash_str_map[key] = val;
      key_str_vec.emplace_back(key);
    }
    assert(tree_str_map.size() == hash_str_map.size());
    assert(tree_str_map.size() == key_str_vec.size());
    std::random_shuffle(key_str_vec.begin(), key_str_vec.end());

    std::default_random_engine random(time(NULL));
    std::uniform_int_distribution<int> int_rand(0, KEY_NUM * KEY_NUM * KEY_NUM);
    for (int i = 0; i < KEY_NUM; i++) {
      uint64_t key = int_rand(random);
      std::string val = str_rand(KEY_LEN);
      tree_int_map[key] = val;
      hash_int_map[key] = val;
      key_int_vec.emplace_back(key);
    }
    assert(tree_int_map.size() == hash_int_map.size());
    assert(tree_int_map.size() == key_int_vec.size());
    std::random_shuffle(key_int_vec.begin(), key_int_vec.end());
    std::cout << "SetupMap Construct !!!" << std::endl;
  }

 public:
  static void PerformSetupMap() { static SetupMap setup_map; }
};

static void bm_tree_str_map(benchmark::State& state) {
  SetupMap::PerformSetupMap();
  size_t idx = 0;
  size_t len = key_str_vec.size();
  for (auto _ : state) {
    auto it = tree_str_map.find(key_str_vec[idx]);
    idx++;
    idx = idx % len;
  }
}
BENCHMARK(bm_tree_str_map);

static void bm_hash_str_map(benchmark::State& state) {
  SetupMap::PerformSetupMap();
  size_t idx = 0;
  size_t len = key_str_vec.size();
  for (auto _ : state) {
    auto it = hash_str_map.find(key_str_vec[idx]);
    idx++;
    idx = idx % len;
  }
}
BENCHMARK(bm_hash_str_map);

static void bm_tree_int_map(benchmark::State& state) {
  SetupMap::PerformSetupMap();
  size_t idx = 0;
  size_t len = key_int_vec.size();
  for (auto _ : state) {
    auto it = tree_int_map.find(key_int_vec[idx]);
    idx++;
    idx = idx % len;
  }
}
BENCHMARK(bm_tree_int_map);

static void bm_hash_int_map(benchmark::State& state) {
  SetupMap::PerformSetupMap();
  size_t idx = 0;
  size_t len = key_int_vec.size();
  for (auto _ : state) {
    auto it = hash_int_map.find(key_int_vec[idx]);
    idx++;
    idx = idx % len;
  }
}
BENCHMARK(bm_hash_int_map);

BENCHMARK_MAIN();
