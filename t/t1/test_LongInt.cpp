// File : main.cpp
// Author : Brysen Landis

#include <iostream>
#include "LongInt.h"


// compares longints and returns if they are equal
void test_LongIntEq()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    std::cout << a << " == " << b << ' ' << (a == b) << "\n";
}


// compares longints and returns if they are not equal
void test_LongIntNotEq()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    std::cout << a << " != " << b << ' ' << (a != b) << "\n";
}


// compares longints and returns if a is less than b
void test_LongIntLt()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    std::cout << a << " < " << b << ' ' << (a <  b) << "\n";
}


// compares longints and returns if a is less than or equal
// to b
void test_LongIntLtE()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    std::cout << a << " <= " << b << ' ' << (a <= b) << "\n";
}


// compares longints and returns if a is greater than b
void test_LongIntGt()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    std::cout << a << " > " << b << ' '<< (a >  b) << "\n";
}


// compares longints and returns if a is greater than or
// equal to b
void test_LongIntGtE()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    std::cout << a << " >= " << b << ' '<< (a >= b) << "\n";
}


// adds the two longints together
void test_LongIntAdd()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    LongInt r = a + b;
    std::cout << a << " + " << b << " = " << r << "\n";
    std::cout << "(size_=" << r.size_ << ", sign_=" << r.sign_ << ")\n";
}


// subtracts the two longints
void test_LongIntSub()
{
    char s1[1000], s2[1000];
    std::cin >> s1 >> s2;
    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);
    
    LongInt r = a - b;
    std::cout << a << " - " << b << " = " << r << "\n";
    std::cout << "(size_=" << r.size_ << ", sign_=" << r.sign_ << ")\n";
}


int main() {

    int choice = 0;

    std::cin >> choice;

    switch (choice)
    {
        case 1:
            test_LongIntEq();
            break;
        case 2:
            test_LongIntNotEq();
            break;
        case 3:
            test_LongIntLt();
            break;
        case 4:
            test_LongIntLtE();
            break;
        case 5:
            test_LongIntGt();
            break;
        case 6:
            test_LongIntGtE();
            break;
        case 7:
            test_LongIntSub();
            break;
        case 8:
            test_LongIntAdd();
            break;
    }

    return 0;
}
