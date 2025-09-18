#include <iostream>

void f3(int * p) // pass by pointer that is incrementing y by 1.
{
    *p = *p + 1;
}

void f2(int * p) // pass by pointer
{
    *p = 2;
}

void f1(int x) // the wrong way to change a variable value. This is pass by value and will
{              // not work.
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

    int y = 42;
    f3(&y);
    std::cout << y << '\n';

    return 0;
}
