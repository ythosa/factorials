#include "gtest/gtest.h"
#include "fmath.h"

TEST(FactorialMathTest, IsqrtValueChecking) {
    EXPECT_EQ(fmath::isqrt(10), 3);
}