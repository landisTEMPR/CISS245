// File : main.cpp
// Author : Brysen Landis

#include <iostream>
#include "LongInt.h"


void test_longint_eq()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

    std::cout << a << " == " << b << ' ' << (a == b) << "\n";
}


void test_longint_noteq()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

    std::cout << a << " != " << b << ' ' << (a != b) << "\n";
}


void test_longint_lt()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

    std::cout << a << " < " << b << ' ' << (a < b) << "\n";
}


void test_longint_lte()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

    std::cout << a << " <= " << b << ' ' << (a <= b) << "\n";
}


void test_longint_gt()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

    std::cout << a << " > " << b << ' ' << (a > b) << "\n";
}


void test_longint_gte()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

    std::cout << a << " >= " << b << ' ' << (a >= b) << "\n";
}


void test_longint_add()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

    LongInt r = a + b;

    std::cout << a << " + " << b << " = " << r << "\n";
}


void test_longint_sub()
{
    char s1[1000], s2[1000];

    std::cin >> s1 >> s2;

    LongInt a = get_longint(s1);
    LongInt b = get_longint(s2);

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
            test_longint_eq();
            break;
        case 2:
            test_longint_noteq();
            break;
        case 3:
            test_longint_lt();
            break;
        case 4:
            test_longint_lte();
            break;
        case 5:
            test_longint_gt();
            break;
        case 6:
            test_longint_gte();
            break;
        case 7:
            test_longint_sub();
            break;
        case 8:
            test_longint_add();
            break;
    }

    return 0;
}
