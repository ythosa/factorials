//
// Created by ythosa on 7/15/20.
//

#ifndef FACTORIALLIB_FALGO_H
#define FACTORIALLIB_FALGO_H

#include <vector>

#define ull unsigned long long

namespace falgo {
    class IFactorial {
        static ull Count(ull n);
    };

    class PrimeSwing : public IFactorial {
    public:
        static ull Product(std::vector<ull> s, ull n, ull m);
        static ull Product(ull sMin, ull n, ull m);

        static ull Swing(ull m, std::vector<ull> primes);

        static ull OddFactorial(ull n, std::vector<ull> primes);

        static ull Count(ull n);
    private:
        static ull GetSimpleValue(ull i);
    };
}

#endif //FACTORIALLIB_FALGO_H
