// File: main.cpp
// Author: Brysen Landis

#include <iostream>
#include "Fraction.h"


void test_Fraction_print()
{
    int xn = 0, xd = 0;
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


void test_Fraction_div()
{
    int xn, xd, yn, yd;
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_mult(xn, xd, yn, yd);
}


void test_Fraction_eq()
{
    int xn, xd, yn, yd;
    std::cin >> xn >> xd >> yn >> yd;
    std::cout << Fraction_eq(xn, xd, yn, yd) << '\n';
}


void test_Fraction_neq()
{
    int xn, xd, yn, yd;
    std::cin >> xn >> xd >> yn >> yd;
    std::cout << Fraction_neq(xn, xd, yn, yd) << '\n';
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
            break;
        case 3:
            test_Fraction_sub();
            break;
        case 4:
            test_Fraction_mult();
            break;
        case 5:
            test_Fraction_div();
            break;
        case 6:
            test_Fraction_eq();
            break;
        case 7:
            test_Fraction_neq();
            break;
    }
    return 0;
}
