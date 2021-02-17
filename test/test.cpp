#include "../lib/ratio.h"

#include <iostream>
#include <gtest/gtest.h>

using ri = ratio::ratio<int>;

TEST(ratio, ctor_n_d_false)
{
    ri a(2, 2, false);
    EXPECT_EQ(a.numerator, 2);
    EXPECT_EQ(a.denominator, 2);
}

TEST(ratio, ctor_n_d_true)
{
    EXPECT_EQ(ri(2, 2).reduce(), ri(1, 1, false));
}

TEST(ratio, ctor_n)
{
    EXPECT_EQ(ri(2), ri(2, 1, false));
}

TEST(ratio, minus)
{
    ri a(1);
    EXPECT_EQ((-a).numerator, -1);
    EXPECT_EQ((-a).denominator, 1);
}

TEST(ratio, reduce_member_1)
{
    ri a(2, 2);
    EXPECT_EQ(a.reduce(), ri(1, 1));
    EXPECT_EQ(a, ri(1, 1));
}

TEST(ratio, reduce_member_2)
{
    ri a(1, -1);
    EXPECT_EQ(a.reduce(), ri(-1, 1));
    EXPECT_EQ(a, ri(-1, 1));
}

TEST(ratio, inverse_member)
{
    ri a(1, 2);
    EXPECT_EQ(a.inverse(), ri(2, 1));
    EXPECT_EQ(a, ri(2, 1));
}

TEST(ratio, inverse)
{
    ri a(1, 2);
    EXPECT_EQ(ratio::inverse(a), ri(2, 1));
    EXPECT_EQ(a, ri(1, 2));
}

TEST(ratio, add)
{
    ri a(1, 2);
    EXPECT_EQ(a + a, ri(1, 1));
    EXPECT_EQ(a, ri(1, 2));
}

TEST(ratio, multiply)
{
    ri a(1, 2);
    EXPECT_EQ(a * a, ri(1, 4));
    EXPECT_EQ(a, ri(1, 2));
}

TEST(ratio, divide)
{
    ri a(1, 2);
    EXPECT_EQ(a / a, ri(1, 1));
    EXPECT_EQ(a, ri(1, 2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
