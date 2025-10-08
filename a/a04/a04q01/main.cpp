// File : a04q01.cpp
// Author : Brysen Landis 

#include <iostream>

void readChar(char* c);   // expects pointer to single char
void readInt(int* i);     // expects pointer to int
void readDouble(double* d);// expects pointer to double

int main()
{
    char c = 0;
    int i = 0;
    double d = 0;

    readChar(&c);   // reads a single non-whitespace char into c
    readInt(&i);    // reads integer into i
    readDouble(&d); // reads double into d

    std::cout << c << std::endl;
    std::cout << i << std::endl;
    std::cout << d << std::endl;
    
    return 0;
}

void readChar(char* c)
{
    std::cin >> *c;
}

void readInt(int* i)
{
    std::cin >> *i;
}

void readDouble(double* d)
{
    std::cin >> *d;
}
