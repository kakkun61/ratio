#include "../lib/ratio.h"

#include <iostream>
#include <gtest/gtest.h>

template<typename T>
using r = ratio::ratio<T>;

using ri = r<int>;

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

TEST(ratio, negate)
{
    ri a(1);
    EXPECT_EQ(a.negate(), ri(-1, 1));
    EXPECT_EQ(a, ri(-1, 1));
}

TEST(ratio, negate_unsigned)
{
    r<unsigned int> a(1);
    EXPECT_ANY_THROW(a.negate());
}

TEST(ratio, minus)
{
    ri a(1);
    EXPECT_EQ((-a).numerator, -1);
    EXPECT_EQ((-a).denominator, 1);
}

TEST(ratio, reduce_member)
{
    ri a(2, 2);
    EXPECT_EQ(a.reduce(), ri(1, 1));
    EXPECT_EQ(a, ri(1, 1));
}

TEST(ratio, reduce_func)
{
    ri a(1, -1);
    EXPECT_EQ(ratio::reduce(a), ri(-1, 1));
    EXPECT_EQ(a, ri(1, -1));
}

TEST(ratio, reduce_func_minus)
{
    ri a(1, -1);
    EXPECT_EQ(a.reduce(), ri(-1, 1));
    EXPECT_EQ(a, ri(1, -1));
}

TEST(ratio, reduce_func_numerator_zero)
{
    ri a(0, 2);
    EXPECT_EQ(a.reduce(), ri(0, 1));
    EXPECT_EQ(a, ri(0, 2));
}

TEST(ratio, reduce_func_denominator_zero)
{
    ri a(2, 0);
    EXPECT_EQ(a.reduce(), ri(1, 0));
    EXPECT_EQ(a, ri(2, 0));
}

TEST(ratio, inverse_member)
{
    ri a(1, 2);
    EXPECT_EQ(a.inverse(), ri(2, 1));
    EXPECT_EQ(a, ri(2, 1));
}

TEST(ratio, inverse_func)
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

TEST(ratio, subtract)
{
    ri a(1, 2);
    EXPECT_EQ(a - a, ri(0, 1));
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

TEST(ratio, to_double_member)
{
    EXPECT_DOUBLE_EQ(ri(1, 2).to_double(), 1. / 2);
}

TEST(ratio, to_double_func)
{
    EXPECT_DOUBLE_EQ(ratio::to_double(ri(1, 2)), 1. / 2);
}

TEST(ratio, to_double_func_nan)
{
    EXPECT_DOUBLE_EQ(ratio::to_double(ri(1, 0)), std::numeric_limits<double>::infinity());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
