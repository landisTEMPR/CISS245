// File: Fraction.h
// Author: Brysen Landis
//-----------------------------------------------------------------------------
// Print fraction modeled by numerator n and denominator d.
//-----------------------------------------------------------------------------

#ifndef FRACTION_H
#define FRACTION_H

void Fraction_print(int n, int d);
void simplify_normalize(int& n, int& d);
void test_Fraction_add(int xn, int xd, int yn, int yd);
void Fraction_add(int xn, int xd, int yn, int yd);
int GCD(int a, int b);

#endif



