#include <iostream>

#include "src/fmath.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << fmath::isqrt(10) << std::endl;

    for (auto r : fmath::range(2, 10)) {
        std::cout << r << std::endl;
    }

    return 0;
}
