#include <iostream>

#include "falgo.h"
#include "fmath.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Factorial of 20 is " << falgo::PrimeSwing::Count(20) << std::endl;
    std::cout << "Isqrt of 10 is " << fmath::isqrt(10) << std::endl;

    for (auto n : fmath::prime_range(0, 20)) {

    }

    return 0;
}
