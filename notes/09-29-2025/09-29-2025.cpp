// pointers & arrays // 09 - 29 - 2025

#include <iostream>


void f(int *p)
{
    
}


int main()
{
    int x = 42;
    int *p = &x;

    f(&x);
    std::cout << p << '\n';
    p = new int;
    std::cout << p << '\n';
    *p = 0;
    std::cout << x << '\n';
    std::cout << p << '\n';
    std::cout << *p << '\n';
    delete p;
    std::cout << *p << '\n';

    return 0;
}
