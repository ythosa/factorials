#pragma once

#include <vector>
#include <algorithm>

#define ull unsigned long long

namespace algo {
	class PrimeSwing : public IFactorial {
	public:
		static ull Product(std::vector<ull> s, ull n, ull m);
		static ull Product(ull sMin, ull n, ull m);

		static ull Swing(ull m, std::vector<ull> primes);

		static ull OddFactorial(ull n, std::vector<ull> primes);

		static ull Count(ull n);
	private:
		static ull GetSimpleValue(ull i);
	};
}
