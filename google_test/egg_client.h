#pragma once

#include <iostream>
#include <string>

namespace GTestDemo {

class EggClient {
  public:
    EggClient() {}
    virtual ~EggClient() {}

    std::string Get(const std::string& key);
    int Post(const std::string& key, const std::string& val);
};
  
}