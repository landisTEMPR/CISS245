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
    return a;
}


void Fraction_add(int xn, int xd, int yn, int yd)
{
    if (xd == 0 || yd == 0)
    {
        std::cout << "undefined\n";
        return;
    }

    int g = GCD(xn, xd);
    if (g != 0) { xn /= g; xd /= g; }

    g = GCD(yn, yd);
    if (g != 0) { yn /= g; yd /= g; }

    int gcdDen = GCD(xd, yd);

    int zn = xn * (yd / gcdDen) + yn * (xd / gcdDen);
    int zd = (xd / gcdDen) * yd;

    simplify_normalize(zn, zd);
    Fraction_print(zn, zd);
}


void Fraction_sub(int xn, int xd, int yn, int yd)
{
    if (xd == 0 || yd == 0)
    {
        std::cout << "undefined\n";
        return;
    }

    int g = GCD(xn, xd);
    if (g != 0) { xn /= g; xd /= g; }

    g = GCD(yn, yd);
    if (g != 0) { yn /= g; yd /= g; }

    int gcdDen = GCD(xd, yd);

    int zn = xn * (yd / gcdDen) - yn * (xd / gcdDen);
    int zd = (xd / gcdDen) * yd;

    simplify_normalize(zn, zd);
    Fraction_print(zn, zd);
}

void Fraction_mult(int xn, int xd, int yn, int yd)
{
    if (xd == 0 || yd == 0)
    {
        std::cout << "undefined\n";
        return;
    }

    int zn = xn * yn;
    int zd = xd * yd;

    simplify_normalize(zn, zd);
    Fraction_print(zn, zd);
}

void Fraction_div(int xn, int xd, int yn, int yd)
{
    if (xd == 0 || yd == 0 || yn == 0)
    {
        std::cout << "undefined\n";
        return;
    }
    
    int zn = xn * yd;
    int zd = xd * yn;

    simplify_normalize(zn, zd);
    Fraction_print(zn, zd);
}


bool Fraction_eq(int xn, int xd, int yn, int yd)
{
    if (xd == 0 || yd == 0) { return false; }

    simplify_normalize(xn, xd);
    simplify_normalize(yn, yd);

    return (xn == yn && xd == yd);
}


bool Fraction_neq(int xn, int xd, int yn, int yd)
{
    if (xd == 0 || yd == 0) { return false; }

    simplify_normalize(xn, xd);
    simplify_normalize(yn, yd);

    if (xn != yn && xd != yd) { return true; }
    else { return false; }
}


bool Fraction_lt(int xn, int xd, int yn, int yd)
{
    if (xd == 0 || yd == 0) { return false; }

    simplify_normalize(xn, xd);
    simplify_normalize(yn, yd);

    return (xn * yd < yn * xd);
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
    }
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
