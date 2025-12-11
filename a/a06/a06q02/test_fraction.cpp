/****************************************************************
FILE : test_fraction.cpp
AUTHOR : Brysen Landis
****************************************************************/

#include <iostream>
#include "Fraction.h"

void test_print()
{
    int n = 0, d = 0;
    std::cin >> n >> d;
    Fraction f = {n, d};
    std::cout << f << std::endl;
}

void test_add()
{
    int n0, d0, n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;
    Fraction r0 = {n0, d0};
    Fraction r1 = {n1, d1};
    std::cout << (r0 + r1) << std::endl;
}

int main()
{
    int option;
    std::cin >> option;
    
    switch (option)
    {
        case 1:
            test_print();
            break;
        case 2:
            test_add();
            break;
    }
    
    return 0;
}
