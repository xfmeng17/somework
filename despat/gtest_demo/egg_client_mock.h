#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#define EggClient Mock_EggClient

namespace EggClient {
class Mock_EggClient {
  public:                                                                                                
  Mock_EggClient() {}                                                                                 
  virtual ~Mock_EggClient() {}                                                                        
                                                                                                        
  MOCK_METHOD(std::string, Get, (const std::string&), ());                                                                                                                                                                                                   
  MOCK_METHOD(bool, Post, (const std::string&, const std::string&), ());
};
}