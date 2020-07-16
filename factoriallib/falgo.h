#ifndef FACTORIALLIB_FALGO_H
#define FACTORIALLIB_FALGO_H

#include <vector>

#define ll long long

namespace falgo {
    class IFactorial {
        static ll Count(ll n);
    };

    /* MethodMustBeInTheInheritors is custom exception type that using
     * if this method cannot be called directly, meaning this method
     * must be overridden in the inheritors. */
    struct MethodMustBeInTheInheritors : public std::exception
    {
        [[nodiscard]] const char * what () const noexcept override
        {
            return "falgo::Factorial::Count(): this method must be defined in the inheritors."
                   "Factorial class is using to implement various factorial algorithms.";
        }
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

    /* RangeError is custom error type. Throwing when the passed
     * argument does not match the allowed interval. */
    struct RangeError : public std::exception
    {
        int left{};
        int right{};

        explicit RangeError(int l, int r) {
            this->left = l;
            this->right = l;
        }

        [[nodiscard]] const char * what () const noexcept override
        {
            std::string err = "The argument passed into function must be >= `" + std::to_string(this->left) +
                              "` and < `" + std::to_string(this->right) + "`!";

            return err.c_str();
        }
    };

    /* TakingFromArray is class for algorithm which just takes value from array */
    class TakingFromArray : public IFactorial {
    public:
        static ll Count(ll n);
    };

    /* InitAndTakeFromArray is class for algorithm which initialise array and return value from it */
    class InitAndTakeFromArray : public IFactorial {
    public:
        static ll Count(ll n);
    };

    /* Tree is class for algorithm for computing the tree */
    class Tree : public IFactorial {
    public:
        static ll Count(ll n);
    private:
        static ll ProdTree(ll l, ll r);
    };

    /* FactFactor is class for algorithm which use factorisation */
    class FactFactor : public IFactorial {
    public:
        static ll Count(ll n);
    };

    /* FactFast is class for algorithm which use analog factorisation algorithm */
    class FactFast : public IFactorial {
    public:
        static ll Count(ll n);
    };

    /* FactNaive is class for algorithm which use faster naive factorial algorithm */
    class FactNaive : public IFactorial {
    public:
        static ll Count(ll n);
    };

    /* SimpleFactNaive is class for algorithm which use simple fact naive algorithm */
    class SimpleFactNaive : public IFactorial {
    public:
        static ll Count(ll n);
    };
}

#endif //FACTORIALLIB_FALGO_H
