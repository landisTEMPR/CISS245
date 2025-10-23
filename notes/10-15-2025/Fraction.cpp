#include <iostream>
#include "Fraction.h"

Fraction Fraction_get(int n, int d)
{
    Fraction ret = {n, d};
    return ret;
}

int Fraction_get_n(const Fraction & f)
{
    return f.n;
}

int Fraction_get_d(const Fraction & f)
{
    return f.d;
}

Fraction & operator+=(Fraction & f0, const Fraction & f1)
{
    f0.n = f0.n * f1.d + f0.d * f1.n;
    f0.d *= f1.d;
    return f0;
}

Fraction & operator+(const Fraction & f1, const Fraction & f0)
{
    Fraction ret = f0;
    return (ret += f1);
}

std::ostream & operator<<(std::ostream & cout, const Fraction & f)
{
    cout << f.n << '/' << f.d;
    return cout;
}

std::istream & operator>>(std::istream & cin, Fraction & f)
{
    int n, d;
    cin >> n >> d;
    f.n = n;
    f.d = d;
    return cin;
}
