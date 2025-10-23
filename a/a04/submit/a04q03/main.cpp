// File : a04q03.cpp
// Name : Brysen Landis

#include <iostream>


// Swaps the values *p, *q
void swap(int *p, int *q)
{
    int t = *q;
    *q = *p;
    *p = t;
}


// Performs bubblesort from *begin to one int before *end.
// For swapping, you should use the above swap function.
void bubblesort(int *begin, int *end)
{
    int *p = begin;
    int *q = end - 1;            

    while (q > begin)
    {
        p = begin;
        while (p < q)
        {
            if (*p > *(p + 1))
            {
                swap(p, p + 1);
            }
            ++p;
        }
        --q;
    }
}


// Prints array from *begin to one int before *end. The print format is
// {1, 4, -2, 42}.
void println(int *begin, int *end)
{
    int *p = begin;
    
    std::cout << '{';
    std::cout << *p;
    ++p;
    
    for (; p < end; ++p)
    {
        std::cout << ", " << *p;
    }
    std::cout << "}\n";

    return;
}


int main()
{
    int x[1024];
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    
    println(&x[0], &x[n]);
    bubblesort(&x[0], &x[n]);
    println(&x[0], &x[n]);
    
    return 0;

}
