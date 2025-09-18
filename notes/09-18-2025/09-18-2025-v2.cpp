#include <iostream>

void swap0(int a, int b)
{
    // int t = a;
    // int a = b;
    // int b = t;
    // return;
}

void swap1(int& a, int& b)
{
    int t = a;
     a = b;
     b = t;
    return;
}

void swap2(int* p, int* q)
{
    int t = *p;
    *p = *q;
    *q = t;
    return;
}

int main()
{
    int x = 0, y = 1;
    swap0(x, y);
    std::cout << x << ' ' << y << '\n';
    
    x = 0; y = 1;
    swap1(x, y);
    std::cout << x << ' ' << y << '\n';

    x = 0; y = 1;
    swap2(&x, &y);
    std::cout << x << ' ' << y << '\n';
    
}
