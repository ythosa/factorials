// prime_sing.cpp: Defines the prime swing factorial class for the static library.
//

#include "pch.h"
#include "fmath.h"
#include "prime_swing.h"

#define ull unsigned long long

namespace algo {
    /* Product() function calculates the product of prime factor lists
        * using the recursive divide-and-conquer method.
    */
    ull PrimeSwing::Product(std::vector<ull> s, ull n, ull m) {
        if (n > m)
            return 1;

        if (n == m)
            return s[n];

        ull k = (n + m) / 2;

        return Product(s, n, k) * Product(s, k + 1, m);
    }

    /* Product() function calculates the product of prime factor lists
        * using the recursive divide-and-conquer method.
    */
    ull PrimeSwing::Product(ull sMin, ull n, ull m) {
        if (n > m)
            return 1;

        if (n == m)
            return sMin + n;

        ull k = (n + m) / 2;

        return Product(sMin, n, k) * Product(sMin, k + 1, m);
    }

    /* Swing() is main function of prime swing
        * algorithm to counting factorial of n
    */
    ull PrimeSwing::Swing(ull m, std::vector<ull> primes) {

        if (m < 4)
            return GetSimpleValue(m);

        ull s = fmath::BisectLeft(primes, 1 + fmath::Isqrt(m));
        ull d = fmath::BisectLeft(primes, 1 + m / 3);
        ull e = fmath::BisectLeft(primes, 1 + m / 2);
        ull g = fmath::BisectLeft(primes, 1 + m);

        std::vector<ull> factors = std::vector<ull>(primes.begin() + e, primes.begin() + g);
        std::vector<ull> primes_snd;
        if (s < d) {
            primes_snd = std::vector<ull>(primes.begin() + s, primes.begin() + d);
            std::copy_if(primes_snd.begin(), primes_snd.end(), std::back_inserter(factors), [&](ull x) { return ((m / x) & 1) == 1; });
        }

        for (auto prime : std::vector<ull>(primes.begin() + 1, primes.begin() + s)) {
            ull p = 1;
            ull q = m;

            while (true) {
                q /= prime;
                if (q == 0)
                    break;
                if ((q & 1) == 1)
                    p *= prime;
            }
            if (p > 1)
                factors.push_back(p);
        }

        return Product(factors, 0, factors.size() - 1);
    }

    /* OddFactorial() function is
        * odding prime array
    */
    ull PrimeSwing::OddFactorial(ull n, std::vector<ull> primes) {
        if (n < 2)
            return 1;

        return (pow(OddFactorial(n / 2, primes), 2)) * Swing(n, primes);
    }

    /* Count() function returns factorial of n
    */
    ull PrimeSwing::Count(ull n) {
        if (n == 0 || n == 1)
            return 1;

        if (n < 10)
            return Product(2, 0, n - 2);

        int bits = n - fmath::BitCounter(n);
        std::vector<ull> primes = fmath::PrimeRange(2, n + 1);

        return OddFactorial(n, primes) * pow(2, bits);
    }

    /* GetSimpleValue() function returns
        * simple values for counting swing
    */
    ull PrimeSwing::GetSimpleValue(ull i) {
        return (ull)1 * ((i == 0) || (i == 1) || (i == 2)) + (ull)3 * (i == 3);
    }
}
