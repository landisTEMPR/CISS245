#include <iostream>
#include "array.h"


void print_arr(int * start, int * end)
{
    for (int * p = start; p < end; p = p + 1)
    {
        std::cout << (*p) << ' ';
    }
    std::cout << '\n';
    return;
}
