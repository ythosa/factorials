#include "gtest/gtest.h"
#include "fmath.h"

#include <vector>

TEST(FactorialMathTest, IsqrtTest) {
    EXPECT_EQ(fmath::isqrt(10),   3);
    EXPECT_EQ(fmath::isqrt(9),    3);
    EXPECT_EQ(fmath::isqrt(25),   5);
    EXPECT_EQ(fmath::isqrt(12),   3);
    EXPECT_EQ(fmath::isqrt(300), 17);
    EXPECT_EQ(fmath::isqrt(325), 18);
}

TEST(FactorialMathTest, PrimeRangeTest) {
    long long correct_range[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    auto tested = fmath::prime_range(0, 19);
    for (long long i = 0; i < sizeof(correct_range) / sizeof(*correct_range); i++) {
        EXPECT_EQ(correct_range[i], tested[i]);
    }
}

TEST(FactorialMathTest, RangeTest) {
    long long correct_range[] = { 10, 11, 12, 13 };
    auto tested = fmath::range(10, 14);
    for (long long i = 0; i < sizeof(correct_range) / sizeof(*correct_range); i++) {
        EXPECT_EQ(correct_range[i], tested[i]);
    }
}

TEST(FactorialMathTest, BisectLeftTest) {
    long long tested = fmath::bisect_left(std::vector<long long> { 1, 2, 5, 10, 100 }, 6);
    EXPECT_EQ(tested, 3);

    tested = fmath::bisect_left(std::vector<long long> {
            1, 2, 5, 10, 100, 123, 12, 50, 41, 37, 62, 22, 21
        }, 20);
    EXPECT_EQ(tested, 7);

    tested = fmath::bisect_left(std::vector<long long> {
            3, 1244, 5, 15, 100, 123, 12, 50, 31237123, 10, 21, 0, 0, 0, 41, 37, 62, 22, 21
        },50);
    EXPECT_EQ(tested, 19);

    tested = fmath::bisect_left(std::vector<long long> {
            3, 1244, 5, 15, 100, 123, 12, 50, 31237123, 10, 21, 0, 0, 0, 41, 37, 62, 22, 21
        }, 3);
    EXPECT_EQ(tested, 0);

    tested = fmath::bisect_left(std::vector<long long> {
            3, 1244, 5, 15, 100, 123, 12, 50, 31237123, 10, 21, 0, 0, 0, 41, 37, 62, 22, 21
        }, 10);
    EXPECT_EQ(tested, 3);
}

TEST(FactorialMathTest, BitCounterTest) {
    EXPECT_EQ(fmath::bit_counter(1),  1);
    EXPECT_EQ(fmath::bit_counter(2),  1);
    EXPECT_EQ(fmath::bit_counter(3),  2);
    EXPECT_EQ(fmath::bit_counter(4),  1);
    EXPECT_EQ(fmath::bit_counter(5),  2);
    EXPECT_EQ(fmath::bit_counter(6),  2);
    EXPECT_EQ(fmath::bit_counter(7),  3);
    EXPECT_EQ(fmath::bit_counter(8),  1);
    EXPECT_EQ(fmath::bit_counter(9),  2);
    EXPECT_EQ(fmath::bit_counter(10), 2);
    EXPECT_EQ(fmath::bit_counter(11), 3);
}

TEST(FactorialMathTest, PowTest) {
    EXPECT_EQ(fmath::pow(1, 2),    1);
    EXPECT_EQ(fmath::pow(2, 2),    4);
    EXPECT_EQ(fmath::pow(2, 3),    8);
    EXPECT_EQ(fmath::pow(3, 2),    9);
    EXPECT_EQ(fmath::pow(3, 3),   27);
    EXPECT_EQ(fmath::pow(4, 2),   16);
    EXPECT_EQ(fmath::pow(4, 3),   64);
    EXPECT_EQ(fmath::pow(4, 4),  256);
    EXPECT_EQ(fmath::pow(5, 2),   25);
    EXPECT_EQ(fmath::pow(5, 3),  125);
    EXPECT_EQ(fmath::pow(5, 4),  625);
    EXPECT_EQ(fmath::pow(5, 5), 3125);
}
