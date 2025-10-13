// File : LongInt.h
// Author : Brysen Landis

#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>

struct LongInt
{
    int x_[1000];
    int size_;
    int sign_;
};

LongInt get_LongInt(const char s[]);
LongInt get_LongInt(int v);
std::ostream & operator<<(std::ostream & out, const LongInt & I);
bool operator==(const LongInt & a, const LongInt & b);
bool operator!=(const LongInt & a, const LongInt & b);
bool operator<(const LongInt & a, const LongInt & b);
bool operator<=(const LongInt & a, const LongInt & b);
bool operator>(const LongInt & a, const LongInt & b);
bool operator>=(const LongInt & a, const LongInt & b);
LongInt operator+(const LongInt & a, const LongInt & b);
LongInt operator-(const LongInt & a, const LongInt & b);
LongInt operator+(const LongInt & a, int b);
LongInt operator+(int a, const LongInt & b);
LongInt operator-(const LongInt & a, int b);
LongInt operator-(int a, const LongInt & b);

#endif
