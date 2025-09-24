// Read pointers backwards.

#include <iostream>

int main()
{
    int x = 42;
    int y = 99;
    int * p = &x;
    std::cout << (*p) << '\n';
    (*p) = 43;
    p = &y;

    const int * q = &x; // q points to an integer value that is constant.
    // *q = 44;
    *p = 44;
    std::cout << x << '\n';

    int * const r = &x; // r is a constant pointer that points to an int value
    
    *r = 45;
    std::cout << x << '\n';

    // *r = &y;

    const int * const s = &x; // s is a const pointer pointing to a integer that is const.
    // *s = 46;
    // *s = &y;
    
    return 0;
}
