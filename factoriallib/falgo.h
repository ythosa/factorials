//
// Created by ythosa on 7/15/20.
//

#ifndef FACTORIALLIB_FALGO_H
#define FACTORIALLIB_FALGO_H

#include <vector>

#define ll long long

namespace falgo {
    class IFactorial {
        static ll Count(ll n);
    };

    class PrimeSwing : public IFactorial {
    public:
        static ll Product(std::vector<ll> s, ll n, ll m);
        static ll Product(ll sMin, ll n, ll m);

        static ll Swing(ll m, std::vector<ll> primes);

        static ll OddFactorial(ll n, const std::vector<ll>& primes);

        static ll Count(ll n);
    private:
        static ll GetSimpleValue(ll i);
    };
}

#endif //FACTORIALLIB_FALGO_H
