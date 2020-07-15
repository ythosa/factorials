#include <iostream>

#include "fmath.h"
#include "falgo.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Factorial of 20 is " << falgo::PrimeSwing::Count(20) << std::endl;
    std::cout << "Isqrt of 10 is " << fmath::isqrt(10) << std::endl;

    return 0;
}
