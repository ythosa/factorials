#ifndef FACTORIALLIB_FMATH_H
#define FACTORIALLIB_FMATH_H

#include <exception>
#include <vector>
#include <cstring>

#define ll long long

namespace fmath {
    std::vector<ll> prime_range(ll f, ll l);

    std::vector<ll> range(ll f, ll l);

    ll isqrt(ll remainder);

    ll bisect_left(std::vector<ll> a, ll x, ll lo=0, ll hi=-1);

    ll bit_counter(ll n);

    ll pow(ll base, ll exp);

    /* NegativeArgumentPassed is custom error type.
     * Throwing when passed argument into function
     * must be non negative. */
    struct NegativeArgumentPassed : public std::exception {
        const char* v{};
        explicit NegativeArgumentPassed(const char* v) {
            this -> v = v;
        };
        [[nodiscard]] const char * what () const noexcept override {
            return std::strcat(
                    std::strcat((char *)"The argument passed into function <", this->v),
                    "> must be non negative"
                    );
        }
    };
}

#endif //FACTORIALLIB_FMATH_H
