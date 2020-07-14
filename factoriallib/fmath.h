#pragma once

#include <vector>

#define ull unsigned long long

namespace fmath {
	static std::vector<ull> PrimeRange(ull f, ull l);
	static std::vector<ull> Range(ull f, ull l);

	template <typename T>
	static int BitCounter(T n);

	template <typename T>
	static T Isqrt(T remainder);

	static ull BisectLeft(std::vector<ull> a, ull x, ull lo = 0, ull hi = -1);
}
