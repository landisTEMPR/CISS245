#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction f0 = Fraction_get(1, 2);
    Fraction f1 = Fraction_get(1, 3);
    std::cout << Fraction_get_n(f0) << ' ' << Fraction_get_d(f0)<< '\n';
    f0 += f1;
    std::cout << f0 << '\n';
    f0 = f0 + f1;
    std::cout << f0 << '\n';

    std::cin >> f0; //operator >> (std::cin , f0)
    std::cout << f0 << '\n';
    ++f0;
    return 0;
}
