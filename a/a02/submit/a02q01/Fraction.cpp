// File: Fraction.cpp // Author: Brysen Landis
#include <iostream>
#include <cstdlib>
#include "Fraction.h"
int GCD(int a, int b)
{
    a = std::abs(a);
    b = std::abs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a; // >= 0
}


void simplify_normalize(int& n, int& d)
{
    int g = GCD(n, d);
    if (g != 0)
    {
        n /= g;
        d /= g;
    }
    if (d < 0)
    {
        n = -n;
        d = -d;
    } // keep denominator positive
}


void Fraction_print(int n, int d)
{
    if (d == 0)
    {
        std::cout << "undefined\n";
        return;
    }
    if (n == 0)
    {
        std::cout << 0 << '\n';
        return;
    }
    
    simplify_normalize(n, d);
    
    if (d == 1)
    {
        std::cout << n << '\n';
    }
    else
    {
        std::cout << n << '/' << d << '\n';
    }
}
