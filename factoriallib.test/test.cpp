// test.cpp : This file contains the testing functions for factoriallib.
// compile with: factoriallib.lib

#include "pch.h"
#include "factoriallib.h"

#define ull unsigned long long

TEST(FactorialTest, CheckingValues) {
	ull factorials[] = { 
		1, 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
		479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
		355687428096000, 6402373705728000, 121645100408832000 
	};

	for (int f = 0; f < 10; f++) {
		EXPECT_EQ(FactorialPrimeSwing::count(f), factorials[f]);
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
