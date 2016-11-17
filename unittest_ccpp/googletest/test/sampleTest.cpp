#include "gtest/gtest.h"
#include "sample.hpp"

TEST(SumTest, PositiveValues)
{
  int total = sum_test(23, 23);
  EXPECT_EQ(46, total);

  total = sum_test(323, 2);
  EXPECT_EQ(325, total);

  EXPECT_EQ(80, sum_test(77, 3));
}

TEST(SumTest, NegativeValues)
{
  int total = sum_test(-23, 23);
  EXPECT_EQ(0, total);

  total = sum_test(-75, 50);
  EXPECT_EQ(-25, total);

  EXPECT_EQ(-8, sum_test(-5, -3));
}

TEST(SumTest, NegativeValues2)
{
  int total = sum_test(-23, 23);
  EXPECT_NE(46, total);
}

TEST(String, StringConcatenation)
{
  EXPECT_EQ("Hello: Me", concatenate_with("Me"));
}
