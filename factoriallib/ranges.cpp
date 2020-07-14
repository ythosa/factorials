#include "pch.h"
#include "fmath.h"

namespace fmath {
    /* PrimeRange() function returns range of prime numbers.
        * The function returns an array with the first
        * element >= f and the last element <= l.
    */
    std::vector<ull> PrimeRange(ull f, ull l) {
        std::vector<int> sieve;
        std::vector<ull> primes;

        for (int i = 1; i < l + 1; ++i)
            sieve.push_back(i);

        sieve[0] = 0;
        for (int i = 2; i < l + 1; ++i) {
            if (sieve[i - 1] != 0) {
                primes.push_back(sieve[i - 1]);
                for (int j = 2 * sieve[i - 1]; j < l + 1; j += sieve[i - 1]) {
                    sieve[j - 1] = 0;
                }
            }
        }

        std::vector<ull> filtered_primes;
        for (unsigned int i = 0; i < primes.size(); ++i) {
            if (primes[i] >= f) {
                filtered_primes.push_back(primes[i]);
            }
        }

        return filtered_primes;
    }

    /* Range() function returns vector where
        * first element >= f and last element < l.
    */
    std::vector<ull> Range(ull f, ull l) {
        std::vector<ull> r;
        while (f < l) {
            r.push_back(f);
            f++;
        }

        return r;
    }
}