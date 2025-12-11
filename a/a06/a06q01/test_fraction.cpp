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
    Fraction f {n, d};
    std::cout << f << std::endl;
}

int main()
{
    int option;
    std::cin >> option;

    switch (option)
    {
        case 1:
            test_print(); break;
    }
    
    return 0;
}
