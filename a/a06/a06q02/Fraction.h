/****************************************************************
FILE : Fraction.h
AUTHOR : Brysen Landis
****************************************************************/

#ifnedf FRACTION_H
#define FRACTION_H

#include <iostream>

STRUCT FRACTION
{
    int n; // numerator
    int d; // denominator
};

std::ostream & operator<<(std::ostream &, const Fraction &);
Fraction operator+(const Fraction &, const Fraction &);

#endif
