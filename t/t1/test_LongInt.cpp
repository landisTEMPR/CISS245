// File : main.cpp
// Author : Brysen Landis

#include <iostream>
#include "LongInt.h"


void test_LongIntEq()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    std::cout << a << " == " << b << ' ' << (a == b) << "\n";
}


void test_LongIntNotEq()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    std::cout << a << " != " << b << ' ' << (a != b) << "\n";
}


void test_LongIntLt()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    std::cout << a << " < " << b << ' ' << (a < b) << "\n";
}


void test_LongIntLtE()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    std::cout << a << " <= " << b << ' ' << (a <= b) << "\n";
}


void test_LongIntGt()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    std::cout << a << " > " << b << ' ' << (a > b) << "\n";
}


void test_LongIntGtE()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    std::cout << a << " >= " << b << ' ' << (a >= b) << "\n";
}


void test_LongIntAdd()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    LongInt r = a + b;

    std::cout << a << " + " << b << " = " << r << "\n";
}


void test_LongIntSub()
{
    char s1[1005], s2[1005];

    std::cin >> s1 >> s2;

    LongInt a = get_LongInt(s1);
    LongInt b = get_LongInt(s2);

    LongInt r = a - b;

    std::cout << a << " - " << b << " = " << r << "\n";
}


int main()
{
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
            return 1;
    }

    return 0;
}
