#include <iostream>
#include "array.h"


int main()
{
    int x[] = {5, 3, 1, 8, 9, 5, 2, 0};
    bubblesort(&x[0], &x[7]);
    print_arr(&x[0], &x[7]); // start address and ending address
    
    return 0;
}
