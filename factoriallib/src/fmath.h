//
// Created by ythosa on 7/15/20.
//

#ifndef FACTORIALLIB_FMATH_H
#define FACTORIALLIB_FMATH_H

#include <exception>
#include <vector>

#define ull unsigned long long

namespace fmath {
    /* NegativeArgumentPassed is custom error type.
     * Throwing when passed argument into function
     * must be non negative. */
    struct NegativeArgumentPassed : public std::exception {
        const char* v{};
    };

    std::vector<ull> prime_range(ull f, ull l);

    std::vector<ull> range(ull f, ull l);

    ull isqrt(ull remainder);

    ull bisect_left(std::vector<ull> a, ull x, ull lo, ull hi);

    ull BitCounter(ull n);
}

#endif //FACTORIALLIB_FMATH_H
