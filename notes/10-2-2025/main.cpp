#include <iostream>


void f()
{
    int * p;
    p = new int[5];
    *p = 2;
    std::cout << (unsigned long long) p << ' ' << (*p) << '\n';
    int * q = p + 4;
    std::cout << (unsigned long long) q << '\n';
    *q = 3;
}


int main()
{
    int x[5];
    std::cout << &x[0] << ' ' << &x[1] << ' ' << (&x[0] + 1) << '\n';
    std::cout << (unsigned long long) &x[0] << ' ' << (unsigned long long) &x[1] << '\n';
    f();
    return 0;
}
