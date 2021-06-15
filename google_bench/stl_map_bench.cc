#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <random>

#include "benchmark/benchmark.h"

std::map<std::string, std::string> tree_str_map;
std::unordered_map<std::string, std::string> hash_str_map;

static std::string strRand(int length) {			// length: 产生字符串的长度
    char tmp;							// tmp: 暂存一个随机数
    std::string buffer;						// buffer: 保存返回值
    
    // 下面这两行比较重要:
    std::random_device rd;					// 产生一个 std::random_device 对象 rd
    std::default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}

static void init_map() {
  for (int i = 0; i < 1000; i ++) {
    std::string key = strRand(20);
    std::string val = strRand(20);
    tree_str_map[key] = val;
    hash_str_map[key] = val;
  }
  assert(tree_str_map.size() == hash_str_map.size());
  return;
}

