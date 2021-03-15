#include "gtest/gtest.h"

#include "egg_client_mock.h"

TEST(GtestDemo, Demo01) {
  int a = 1;
  ASSERT_NE(a, 0);

  std::string s = "abcs";
  EXPECT_EQ(s, "abcs");

  bool b1 = false;
  EXPECT_FALSE(b);

  bool b2 = false;
  EXPECT_TRUE(b);

  EXPECT_TRUE(ret);
}

