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
void test_Fraction_sub(int xn, int xd, int yn, int yd);
void test_Fraction_mult(int xn, int xd, int yn, int yd);
void test_Fraction_div(int xn, int xd, int yn, int yd);
void test_Fraction_eq(int xn, int xd, int yn, int yd);
void test_Frxaction_neq(int xn, int xd, int yn, int yd);
void Fraction_add(int xn, int xd, int yn, int yd);
void Fraction_sub(int xn, int xd, int yn, int yd);
void Fraction_mult(int xn, int xd, int yn, int yd);
void Fraction_div(int xn, int xd, int yn, int yd);
bool Fraction_eq(int xn, int xd, int yn, int yd);
bool Fraction_neq(int xn, int xd, int yn, int yd);
int GCD(int a, int b);

#endif



