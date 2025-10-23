#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction
{
    int n, d;
};

Fraction Fraction_get(int n, int d);
int Fraction_get_n(const Fraction &);
int Fraction_get_d(const Fraction &);
Fraction & operator+=(Fraction &, const Fraction &);
Fraction & operator+(const Fraction &, const Fraction &);
std::ostream & operator<<(std::ostream & cout, const Fraction &);
std::istream & operator>>(std::istream & cin, Fraction & f);

#endif
