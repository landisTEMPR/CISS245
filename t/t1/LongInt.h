#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>

struct LongInt
{
    int x_[1000]; // digitsx
    int size_;    // number of digits in use (>= 1)
    int sign_;    // is int pos or neg
};
 
LongInt get_LongInt(const char s[]);
LongInt get_LongInt(int v);
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
std::ostream & operator<<(std::ostream & out, const LongInt & I);

#endif 
