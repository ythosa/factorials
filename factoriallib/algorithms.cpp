#include "pch.h"
#include "fmath.h"

namespace fmath {
    /* Isqrt() function is used to get the integer square root of the given
        * non - negative integer value n.This method returns the floor value
        * of the exact square root of n or equivalently the greatest integer
        * a such that a2 <= n
    */
    template <typename T>
    T Isqrt(T remainder) {
        if (remainder < 0) return 0;

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

    /* BisectLeft() fucntion returns the index where to insert item x in list a, assuming a is sorted.
        * The return value i is such that all e in a[:i] have e < x, and all e in
        * a[i:] have e >= x.  So if x already appears in the list, a.insert(i, x) will
        * insert just before the leftmost x already there.
        * Optional args lo (default 0) and hi (default len(a)) bound the
        * slice of a to be searched.
    */
    ull BisectLeft(std::vector<ull> a, ull x, ull lo, ull hi) {
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

    /* BitCounter() function returns the number of
        * units in the binary representation of a number
    */
    template <typename T>
    int BitCounter(T n) {
        unsigned int count = 0;
        for (; n; count++)
            n &= (n - 1);

        return count;
    }
}
