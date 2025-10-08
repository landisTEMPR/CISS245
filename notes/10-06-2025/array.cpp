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


void swap(int * p, int * q)
{
    int t = *p;
    *p = *(q + 1);
    *(q + 1) = t;

    return;
}


void bubblesort(int * start, int * end)
{
    for (int * q = end; q >= start; --q)
    {
        for (int * p = start; p < q - 1; ++p)
        {
            if (*p > *p + 1)
            {
                swap(p, p + 1);
            }
        }
    }

    return;
}
