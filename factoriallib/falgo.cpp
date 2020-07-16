#include <vector>
#include <algorithm>
#include "fmath.h"
#include "falgo.h"

namespace falgo {
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


    /* --- Prime Swing --- */

    /* Count() function for any factorial counting algorithm. */
    ll IFactorial::Count(ll) {
        throw MethodMustBeInTheInheritors();
    }

    /* Product() function calculates the product of prime factor lists
     * using the recursive divide-and-conquer method. */
    ll PrimeSwing::Product(std::vector<ll> s, ll n, ll m) {
        if (n > m)
            return 1;

        if (n == m)
            return s[n];

        ll k = (n + m) / 2;

        return Product(s, n, k) * Product(s, k + 1, m);
    }

    /* Product() function calculates the product of prime factor lists
     * using the recursive divide-and-conquer method. */
    ll PrimeSwing::Product(ll sMin, ll n, ll m) {
        if (n > m)
            return 1;

        if (n == m)
            return sMin + n;

        ll k = (n + m) / 2;

        return Product(sMin, n, k) * Product(sMin, k + 1, m);
    }

    /* Swing() is main function of prime swing
     * algorithm to counting factorial of n. */
    ll PrimeSwing::Swing(ll m, std::vector<ll> primes) {

        if (m < 4)
            return GetSimpleValue(m);

        ll s = fmath::bisect_left(primes, 1 + fmath::isqrt(m));
        ll d = fmath::bisect_left(primes, 1 + m / 3);
        ll e = fmath::bisect_left(primes, 1 + m / 2);
        ll g = fmath::bisect_left(primes, 1 + m);

        std::vector<ll> factors = std::vector<ll>(primes.begin() + e, primes.begin() + g);
        std::vector<ll> primes_snd;
        if (s < d) {
            primes_snd = std::vector<ll>(primes.begin() + s, primes.begin() + d);
            std::copy_if(primes_snd.begin(), primes_snd.end(), std::back_inserter(factors),
                    [&](ll x) { return ((unsigned ll)(m / x) & 1u) == 1; });
        }

        for (auto prime : std::vector<ll>(primes.begin() + 1, primes.begin() + s)) {
            ll p = 1;
            ll q = m;

            while (true) {
                q /= prime;
                if (q == 0)
                    break;
                if (((unsigned ll)q & 1u) == 1)
                    p *= prime;
            }
            if (p > 1)
                factors.push_back(p);
        }

        return Product(factors, 0, (ll)factors.size() - 1);
    }

    /* OddFactorial() function is odding prime array. */
    ll PrimeSwing::OddFactorial(ll n, const std::vector<ll>& primes) {
        if (n < 2)
            return 1;

        return (fmath::pow(OddFactorial(n / 2, primes), 2)) * Swing(n, primes);
    }

    /* Count() function returns factorial of n. */
    ll PrimeSwing::Count(ll n) {
        if (n == 0 || n == 1)
            return 1;

        if (n < 10)
            return Product(2, 0, n - 2);

        ll bits = n - fmath::bit_counter(n);
        std::vector<ll> primes = fmath::prime_range(2, n + 1);

        return OddFactorial(n, primes) * fmath::pow(2, bits);
    }

    /* GetSimpleValue() function returns
        * simple values for counting swing
    */
    ll PrimeSwing::GetSimpleValue(ll i) {
        return (ll)1 * ((i == 0) || (i == 1) || (i == 2)) + (ll)3 * (i == 3);
    }


    /* --- Simple Recursion --- */

    /* Count() function returns factorial of n. */
    ll SimpleRecursion::Count(ll n) {
        if (n == 0) return 1;
        return n * SimpleRecursion::Count(n - 1);
    }


    /* --- Simple While --- */

    /* Count() function returns factorial of n. */
    ll SimpleWhile::Count(ll n) {
        if (n == 0) return 1;

        ll res = n;
        while (n > 1) {
            res *= --n;
        }

        return res;
    }


}
