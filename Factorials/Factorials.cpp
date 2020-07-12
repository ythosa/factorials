#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

ull const simple_values[] = { 1,1,1,3 };

template <typename T>
T isqrt(T remainder)
{
    if (remainder < 0) // if type is unsigned this will be ignored = no runtime  
        return 0; // negative number ERROR  

    type place = (T)1 << (sizeof(T) * 8 - 2); // calculated by precompiler = same runtime as: place = 0x40000000  
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
    std::vector<ull> primes_snd = std::vector<ull>(primes.begin() + s, primes.end() + d);
    std::copy_if(primes_snd.begin(), primes_snd.end(), std::back_inserter(factors), [&](ull x) { return (m / x) & 1 == 1; });

    for (auto prime : std::vector<ull>(primes.begin() + 1, primes.begin() + s)) {
        ull p, q = 1, m;
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

int main() {
    std::cout << "Hello World!\n";
}
