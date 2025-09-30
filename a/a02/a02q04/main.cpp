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


void test_Fraction_add()
{
    int xn, xd, yn, yd;
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_add(xn, xd, yn, yd);
}


void test_Fraction_mult()
{
    int xn, xd, yn, yd;
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_mult(xn, xd, yn, yd);
}

void test_Fraction_sub()
{
    int xn, xd, yn, yd;
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_sub(xn, xd, yn, yd);
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
        case 2:
            test_Fraction_add();
        case 3:
            test_Fraction_sub();
        case 4:
            test_Fraction_mult();
    }
    return 0;
}
