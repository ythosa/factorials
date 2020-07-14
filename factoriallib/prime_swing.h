#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ull unsigned long long

namespace factoriallib {
	class PrimeSwing {
	public:
		template <typename T>
		static T Isqrt(T remainder);

		static ull BisectLeft(std::vector<ull> a, ull x, ull lo = 0, ull hi = -1);

		static std::vector<ull> PrimeRange(ull f, ull l);
		static std::vector<ull> Range(ull f, ull l);

		static ull Product(std::vector<ull> s, ull n, ull m);
		static ull Swing(ull m, std::vector<ull> primes);
		static ull OddFactorial(ull n, std::vector<ull> primes);

		template <typename T>
		static int BitCounter(T n);

		static ull Count(ull n);

	//private:
		static ull GetSimpleValue(ull i);
	};
}
