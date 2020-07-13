#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ull unsigned long long

ull const simple_values[] = { 1,1,1,3 };

template <typename T>
T isqrt(T remainder)
{
    if (remainder < 0) // if type is unsigned this will be ignored = no runtime  
        return 0; // negative number ERROR  

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

/*  Return the index where to insert item x in list a, assuming a is sorted.
    The return value i is such that all e in a[:i] have e < x, and all e in
    a[i:] have e >= x.  So if x already appears in the list, a.insert(i, x) will
    insert just before the leftmost x already there.
    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched. */
ull bisect_left(std::vector<ull> a, ull x, ull lo = 0, ull hi = -1) {
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
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] >= f) {
            filtered_primes.push_back(primes[i]);
        }
    }

    return filtered_primes;
}

template <typename T>
void print(std::vector<T> const& input)
{
    for (auto const& i : input) {
        std::cout << i << " ";
    }
}

std::vector<ull> range(ull f, ull l) {
    std::vector<ull> r;
    while (f < l) {
        r.push_back(f);
        f++;
    }

    return r;
}

ull product(std::vector<ull> s, ull n, ull m) {
    if (n > m)
        return 1;
    
    if (n == m)
        return s[n];

    ull k = (n + m) / 2;

    return product(s, n, k) * product(s, k + 1, m);
}

ull swing(ull m, std::vector<ull> primes) {

    if (m < 4)
        return simple_values[m];

    ull s = bisect_left(primes, 1 + isqrt(m));
    ull d = bisect_left(primes, 1 + m / 3);
    ull e = bisect_left(primes, 1 + m / 2);
    ull g = bisect_left(primes, 1 + m);

    std::vector<ull> factors = std::vector<ull>(primes.begin() + e, primes.begin() + g);
    std::vector<ull> primes_snd;
    if (s < d) {
        primes_snd = std::vector<ull>(primes.begin() + s, primes.begin() + d);
        std::copy_if(primes_snd.begin(), primes_snd.end(), std::back_inserter(factors), [&](ull x) { return (m / x) & 1 == 1; });
    }

    for (auto prime : std::vector<ull>(primes.begin() + 1, primes.begin() + s)) {
        ull p = 1;
        ull q = m;

        while (true) {
            q /= prime;
            if (q == 0)
                break;
            if (q & 1 == 1)
                p *= prime;
        }
        if (p > 1)
            factors.push_back(p);
    }

    return product(factors, 0, factors.size() - 1);
}

ull odd_factorial(ull n, std::vector<ull> primes) {
    if (n < 2)
        return 1;

    return (pow(odd_factorial(n / 2, primes), 2)) * swing(n, primes);
}

template <typename T>
int bit_counter(T n) {
    unsigned int count = 0;
    for (; n; count++)
        n &= (n - 1);

    return count;
}

ull eval(ull n) {
    if (n < 10)
        return product(range(2, n + 1), 0, n - 2);

    int bits = n - bit_counter(n);
    std::vector<ull> primes = prime_range(2, n + 1);

    return odd_factorial(n, primes) * pow(2, bits);
}

int main() {
    std::cout << eval(11);
}
