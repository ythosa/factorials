// factorials.cpp : This file contains the 'main' function. Program execution begins and ends there.
// compile with: factoriallib.lib

#include <iostream>
#include "factoriallib.h"

int main()
{
    std::cout << "Hello World!\n";
    //std::cout << "Factorial of 19 is " << factoriallib::PrimeSwing::Count(19);
    std::cout << factoriallib::PrimeSwing::GetSimpleValue(1) << factoriallib::PrimeSwing::GetSimpleValue(2) << factoriallib::PrimeSwing::GetSimpleValue(3);
}
