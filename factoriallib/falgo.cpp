#include <vector>
#include <algorithm>
#include <string>

#include "fmath.h"
#include "falgo.h"

namespace falgo {
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


    /* --- Taking From the Array --- */

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

    /* _factorials is array of correct factorial values.
     * Indexes in this array match factorial function of each index. */
    ll _factorials[] = {
            1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
            479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
            355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000
    };

    /* Count() function returns factorial of n. */
    ll TakingFromArray::Count(long long int n) {
        if (n >= 0 && n < sizeof(_factorials)/sizeof(*_factorials))
            return _factorials[n];
        else
            throw RangeError(0, sizeof(_factorials)/sizeof(*_factorials));
    }


    /* --- Prod Tree --- */

    /* Count() function returns factorial of n. */
    ll Tree::Count(long long int n) {
        if (n < 0)
            throw fmath::NegativeArgumentPassed("n");
        if (n == 0)
            return 1;
        if (n == 1 || n == 2)
            return n;

        return Tree::ProdTree(2, n);
    }

    /* ProdTree() function counts tree. */
    ll Tree::ProdTree(ll l, ll r) {
        if (l > r)
            return 1;
        if (l == r)
            return l;
        if ((r - l) == 1)
            return l * r;

        ll m = (l + r) / 2;
        return ProdTree(l, m) * ProdTree(m + 1, r);
    }


    /* --- Fact Factorial --- */

    /* Count() function returns factorial of n. */
    ll FactFactor::Count(ll n) {
        if (n < 0)
            throw fmath::NegativeArgumentPassed("n");
        if (n == 0)
            return 1;
        if (n == 1 || n == 2)
            return n;

        bool u[n+1]; // markers for the Eratosthenes sieve
        for (ll i = 0; i <= n + 1; i++) {
            u[i] = false;
        }

        std::vector<std::pair<ll, ll>> p; // multipliers and their exponents

        for (ll i = 2; i <= n; ++i) {
            if (!u[i]) { // if i is prime number
                // consider the exponent in the decomposition
                ll k = n / i;
                ll c = 0;
                while (k > 0) {
                    c += k;
                    k /= i;
                }

                //remember the multiplier and its exponent
                p.emplace_back(i, c);

                // sieve composite numbers using the sieve
                ll j = 2;
                while (i * j <= n) {
                    u[i * j] = true;
                    ++j;
                }
            }
        }

        // counting factorial
        ll r = 1;
        for (ll i = p.size() - 1; i >= 0; i--) {
            r *= fmath::pow(p[i].first, p[i].second);
        }

        return r;
    }

    /* --- Fast Fact Factorial --- */

    /* Count() function returns factorial of n. */
    ll FactFast::Count(ll n) {
        ll p = 0, c = 0;
        while ((n >> p) > 1) {
            p++;
            c += n >> p;
        }

        ll r = 1, k = 1;
        for (;p >= 0; p--) {
            ll n1 = n >> p;
            ll x = 1;
            ll a = 1;
            for (; k <= n1; k += 2) {
                if (a * k < std::numeric_limits<ll>::max()) {
                    a *= k;
                } else {
                    x *= a;
                    a = k;
                }
            }
            r *= fmath::pow(x * a, p + 1);
        }
        return r << c;
    }

    /* --- Fact Naive --- */

    /* Count() function returns factorial of n. */
    ll FactNaive::Count(long long int n) {
        if (n <= 1) {
            return 1;
        }

        ll r1 = 1, r2 = 1, r3 = 1, r4 = 1;
        ll i;
        for (i = n; i > 4; i -= 4) {
            r1 *= i;
            r2 *= i - 1;
            r3 *= i - 2;
            r4 *= i - 3;
        }

        ll mult = i == 4 ? 24 : i == 3 ? 6 : i == 2 ? 2 : 1;
        return (r1 * r2) * (r3 * r4) * mult;
    }


    /* --- Simple Fact Naive --- */

    /* Count() function returns factorial of n. */
    ll SimpleFactNaive::Count(long long int n) {
        ll r = 1;
        for (int i = 2; i <= n; ++i) {
            r *= i;
        }

        return r;
    }
}
