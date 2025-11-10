#include <iostream>
#include "Rational.h"

int main()
{
    Rational r0(1, 2);
    //r0.print();
    std::cout << r0 << '\n';

    r0.set_n(9999);
    std::cout << r0 << '\n';
    std::cout << r0.get_n() << '\n';

    std::cout << r0.n() << '\n';
    r0.n() = 54321;
    std::cout << r0 << '\n';

    std::cin >> r0; // operator>>(std::cin , r0)
    std::cout << r0 << '\n';

    Rational r1(1, 2);
    Rational r2(1, 3);
    /*
    r1 += r2; // same as
              // 1. operator+=(r1, r2)
              // 2. r1.operator+=(r2)
              // r0 = (r1 += r2) 
    std::cout << r1 << '\n';
    */
    //Rational r3 = (r1 += r2);
    //std::cout << r3 << '\n';

    Rational r3(0, 1);
    r3 = r1 + r2;
    // r1 + r2:
    // same as
    // 1. operator+(r1, r2)
    // 2. r1.operator+(r2)
    std::cout << r3 << '\n';
    
    r3 = r1 - r2; // r1 - r2 same as r1.operator-(r2)
    // r1 + r2:
    // same as
    // 1. operator+(r1, r2)
    // 2. r1.operator+(r2)
    std::cout << r3 << '\n';

    // 2.2 + double(1)
    // std::cout << r0 + 1 // call r0.operator+(i)
    //           << '\n';

    Rational r4(5);
    std::cout << r4 << '\n';

    Rational r5;
    std::cout << r5 << '\n';

    std::cout << r4 + 1 // r4 + 1 same as r4.operator+(1)
                        // operator+() expects Rational you have an int 1
                        // operator+(1) is same as operator+(Rational(1))
              << '\n';

    r4 += 1;
    
    return 0;
    
}
