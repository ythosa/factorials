#ifndef FACTORIALLIB_FALGO_H
#define FACTORIALLIB_FALGO_H

#include <vector>

#define ll long long

namespace falgo {
    class IFactorial {
        static ll Count(ll n);
    };

    /* PrimeSwing is class for prime swing algorithm */
    class PrimeSwing : public IFactorial {
    public:
        static ll Product(std::vector<ll> s, ll n, ll m);
        static ll Product(ll sMin, ll n, ll m);

        static ll Count(ll n);
    private:
        static ll GetSimpleValue(ll i);
        static ll Swing(ll m, std::vector<ll> primes);
        static ll OddFactorial(ll n, const std::vector<ll>& primes);
    };

    /* SimpleRecursion is class for simple recursion algorithm */
    class SimpleRecursion : public IFactorial {
    public:
        static ll Count(ll n);
    };

    /* SimpleWhile is class for simple recursion algorithm */
    class SimpleWhile : public IFactorial {
    public:
        static ll Count(ll n);
    };

    /* TakingFromArray is class for algorithm which just takes value from array */
    class TakingFromArray : public IFactorial {
    public:
        static ll Count(ll n);
    };
}

#endif //FACTORIALLIB_FALGO_H
