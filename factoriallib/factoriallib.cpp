// factoriallib.cpp: Defines the factorial class for the static library.
//

#include "pch.h"
#include "factoriallib.h"

#define ull unsigned long long

namespace factoriallib {
    /* Print() function prints vector of any type.
    */
    template <typename T>
    void Factorials::Print(std::vector<T> const& input) {
        for (auto const& i : input) {
            std::cout << i << " ";
        }
    }
}
