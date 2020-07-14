// prime_sing.cpp: Defines the prime swing factorial class for the static library.
//

#include "pch.h"

#define ull unsigned long long

namespace factoriallib {
    /* Isqrt() function is used to get the integer square root of the given
        * non - negative integer value n.This method returns the floor value
        * of the exact square root of n or equivalently the greatest integer
        * a such that a2 <= n
    */
    template <typename T>
    T PrimeSwing::Isqrt(T remainder) {
        if (remainder < 0) return 0;

        T place = (T)1 << (sizeof(T) * 8 - 2); // calculated by precompiler = same runtime as: place = 0x40000000  
        while (place > remainder)
            place /= 4; // optimized by complier as place >>= 2  

        T root = 0;
        while (place)
        {
            if (remainder >= root + place)
            {
                remainder -= root + place;
                root += place * 2;
            }
            root /= 2;
            place /= 4;
        }
        return root;
    }

    /* BisectLeft() fucntion returns the index where to insert item x in list a, assuming a is sorted.
        * The return value i is such that all e in a[:i] have e < x, and all e in
        * a[i:] have e >= x.  So if x already appears in the list, a.insert(i, x) will
        * insert just before the leftmost x already there.
        * Optional args lo (default 0) and hi (default len(a)) bound the
        * slice of a to be searched.
    */
    ull PrimeSwing::BisectLeft(std::vector<ull> a, ull x, ull lo, ull hi) {
        if (lo < 0) {
            throw "lo must be non-negative";
        }

        if (hi == -1) {
            hi = a.size();
        }

        ull mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (a[mid] < x)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }

    /* PrimeRange() function returns range of prime numbers.
        * The function returns an array with the first
        * element >= f and the last element <= l.
    */
    std::vector<ull> PrimeSwing::PrimeRange(ull f, ull l) {
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
    std::vector<ull> PrimeSwing::Range(ull f, ull l) {
        std::vector<ull> r;
        while (f < l) {
            r.push_back(f);
            f++;
        }

        return r;
    }

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

        

    /* Swing() is main function of prime swing
        * algorithm to counting factorial of n
    */
    ull PrimeSwing::Swing(ull m, std::vector<ull> primes) {

        if (m < 4)
            return GetSimpleValue(m);

        ull s = BisectLeft(primes, 1 + Isqrt(m));
        ull d = BisectLeft(primes, 1 + m / 3);
        ull e = BisectLeft(primes, 1 + m / 2);
        ull g = BisectLeft(primes, 1 + m);

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

    /* BitCounter() function returns the number of
        * units in the binary representation of a number
    */
    template <typename T>
    int PrimeSwing::BitCounter(T n) {
        unsigned int count = 0;
        for (; n; count++)
            n &= (n - 1);

        return count;
    }

    /* Count() function returns factorial of n
    */
    ull PrimeSwing::Count(ull n) {
        if (n == 0 || n == 1)
            return 1;

        if (n < 10)
            return Product(Range(2, n + 1), 0, n - 2);

        int bits = n - BitCounter(n);
        std::vector<ull> primes = PrimeRange(2, n + 1);

        return OddFactorial(n, primes) * pow(2, bits);
    }

    /* GetSimpleValue() function returns
        * simple values for counting swing
    */
    ull PrimeSwing::GetSimpleValue(ull i) {
        return (ull)1 * ((i == 0) || (i == 1) || (i == 2)) + (ull)3 * (i == 3);
    }
}
