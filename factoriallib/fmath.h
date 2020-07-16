#ifndef FACTORIALLIB_FMATH_H
#define FACTORIALLIB_FMATH_H

#include <exception>
#include <vector>

#define ll long long

namespace fmath {
    std::vector<ll> prime_range(ll f, ll l);

    std::vector<ll> range(ll f, ll l);

    ll isqrt(ll remainder);

    ll bisect_left(std::vector<ll> a, ll x, ll lo=0, ll hi=-1);

    ll bit_counter(ll n);

    ll pow(ll base, ll exp);
}

#endif //FACTORIALLIB_FMATH_H
