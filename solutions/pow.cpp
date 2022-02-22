/*

1.0.0

Author: Bryce Tuppurainen Feb-2022

This is the solution to challenge-one and is a simple implementation of a custom iterative pow function that is
extremely inefficient, used for demonstration purposes only as the standard library cmath has the pow functions included for doubles, float
long long, etc.

*/

#include <iostream>

int pow(int base, int exponent);

int main()
{
    int base, exponent = 1;
    while (base != 0)
    {
        std::cout << "Base value? (0 to exit): ";
        std::cin >> base;
        std::cout << "Exponent?: ";
        std::cin >> exponent;
        std::cout << base << " to the power of " << exponent << " is equal to " << pow(base, exponent) << std::endl;
    }
    return 0;
}

int pow(int base, int exponent)
{
    if (base == 0) return 0;
    int output = 1;
    for (int iter = 0; iter < exponent; iter++) output *= base;
    return output;
}