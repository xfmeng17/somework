#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bazel/test1/include/test1.h"

TEST(Test2, demo1) {
  std::string str = "bazel_google_tset";
  EXPECT_EQ(str, "bazel_google_tset");
}

TEST(Test2, demo2) {
  int a = 1;
  int b = 2;
  EXPECT_EQ(test1_add(a, b), 3);
  EXPECT_EQ(test1_inline_add(a, b), 3);
}
