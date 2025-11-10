/****************************************************************
FILE : Fraction.cpp
AUTHOR : Brysen Landis
****************************************************************/

#include <iostream>
#include <cmath> 
#include "Fraction.h"


std::ostream & operator<<(std::ostream & cout, const Fraction  & r)
{
    if (r.d == 0)
    {
        return cout << "undefined";
    }
    else if (r.n == 0)
    {
        return cout << 0;
    }
    
    Fraction t = r;
    simplify(t);
        
    if (t.n < 0)
    { 
        return cout << t.n << '/' << std::abs(t.d);
    }
    else if (t.d < 0)
    {
         return cout << '-' << t.n << '/' << std::abs(t.d);
    }
    else
    {
        return cout << t.n << '/' << t.d;
    }
    return cout;
}


Fraction operator+(const Fraction & x, const Fracion & y)
{
    int a, b;
    Fraction t = {a, b};
}


Fraction & simplify(Fraction & t)
{
    int g = GCD(t);
    if (g != 0)
    {
        t.n /= g;
        t.d /= g;
    }
    if (t.d < 0)
    {
        t.n = -(t.n);
        t.d = -(t.d);
    }

    return t;
}


int GCD(Fraction & t)
{
    int a = std::abs(t.n);
    int b = std::abs(t.d);

    if (a == 0) { return a; }
    if (b == 0) { return b; }

    while (b != 0)
    {
        int q = b;
        b = a % b;
        a = q;
    }
    
    return a;   
}
