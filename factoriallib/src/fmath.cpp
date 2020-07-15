//
// Created by ythosa on 7/15/20.
//

#include <vector>
#include <exception>
#include <cstring>

#define ull unsigned long long

namespace fmath {
    /* NegativeArgumentPassed is custom error type.
     * Throwing when passed argument into function
     * must be non negative. */
    struct NegativeArgumentPassed : public std::exception
    {
        const char* v{};

        explicit NegativeArgumentPassed(const char* v) {
            this->v = v;
        }

        [[nodiscard]] const char * what () const noexcept override
        {
            return std::strcat(
                    std::strcat((char *)"The argument passed into function <", this->v),
                    "> must be non negative"
                    );
        }
    };

    /* prime_range() function returns range of prime numbers.
     * The function returns an array with the first
     * element >= f and the last element <= l. */
    std::vector<ull> prime_range(ull f, ull l) {
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
        for (unsigned long long & prime : primes) {
            if (prime >= f) {
                filtered_primes.push_back(prime);
            }
        }

        return filtered_primes;
    }

    /* range() function returns vector where
     * first element >= f and last element < l. */
    std::vector<ull> range(ull f, ull l) {
        std::vector<ull> r;
        while (f < l) {
            r.push_back(f);
            f++;
        }

        return r;
    }

    /* isqrt() function is used to get the integer square root of
     * the given non - negative integer value n. This method returns
     * the floor value of the exact square root of n or equivalently
     * the greatest integer a such that a2 <= n. */
    ull isqrt(ull remainder) {
        if (remainder < 0) {
            throw NegativeArgumentPassed("remainder");
        }

        ull place = (ull)1 << (sizeof(ull) * 8 - 2); // calculated by precompiler = same runtime as: place = 0x40000000
        while (place > remainder)
            place /= 4; // optimized by compiler as place >>= 2

        ull root = 0;
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

    /* bisect_left() function returns the index where to insert item x
     * in list a, assuming a is sorted. The return value i is such that
     * all e in a[:i] have e < x, and all e in a[i:] have e >= x.
     * So if x already appears in the list, a.insert(i, x) will insert just
     * before the leftmost x already there. Optional args lo (default 0) and
     * hi (default len(a)) bound the slice of a to be searched. */
    ull bisect_left(std::vector<ull> a, ull x, ull lo, ull hi) {
        if (lo < 0) {
            throw NegativeArgumentPassed("lo");
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

    /* BitCounter() function returns the number of
     * units in the binary representation of a number. */
    ull BitCounter(ull n) {
        ull count = 0;
        for (; n; count++)
            n &= (n - 1);

        return count;
    }
}
