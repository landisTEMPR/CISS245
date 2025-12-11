/****************************************************************
FILE : Fraction.h
AUTHOR : Brysen Landis
****************************************************************/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

struct Fraction
{
    int n; // numerator
    int d; // denominator
};

std::ostream & operator<<(std::ostream &, const Fraction &);
Fraction & simplify(Fraction &);
int GCD(Fraction &);

#endif
