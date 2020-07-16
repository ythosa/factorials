#include <iostream>

#include "falgo.h"
#include "fmath.h"

int main() {

    std::cout <<  "Factorial of 10 is " << falgo::SimpleRecursion::Count(10) << std::endl;
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Factorial of 20 is " << falgo::PrimeSwing::Count(20) << std::endl;
    std::cout << "Isqrt of 10 is " << fmath::isqrt(10) << std::endl;

    std::cout <<  "Factorial of 10 is " << falgo::SimpleRecursion::Count(10) << std::endl;

    return 0;
}
