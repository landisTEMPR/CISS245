// File: main.cpp
// Author: Brysen Landis

#include <iostream>
#include "Fraction.h"


void test_Fraction_print()
{
    int xn = 0, xd = 0; // numerator and denominator of a fraction
    std::cin >> xn >> xd;
    Fraction_print(xn, xd);
    std::cout << std::endl;
}


int main()
{
    int option;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_Fraction_print();
            break;
    }
    return 0;
}
