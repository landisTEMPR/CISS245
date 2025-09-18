#include <iostream>

void f2(int * p)
{
    *p = 2;
}

void f1(int x) // the wrong way
{
    x = 1;
    return;
}

void f0(int & r) // the right way to use pass by reference
{
    r = 0;
    return;
}

int main()
{
    int x = 42;
    f0(x);
    std::cout << x << '\n';

    x = 42;
    f2(&x);
    std::cout << x << '\n';

    return 0;
}
