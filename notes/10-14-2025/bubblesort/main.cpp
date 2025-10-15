#include <iostream>

void bubblesort(int* start, int* end)
{
    bool swapped = true;
    int *p;

    while (swapped)
    {
        swapped = false;

        for (p = start; p < end - 1; ++p)
        {
            if (*p > *(p + 1))
            {
                int t = *p;
                *p = *(p + 1);
                *(p + 1) = t;

                swapped = true;
            }
        }
        --end;
    }

    return;
}


int main()
{
    int x[] = {9, 2, 7, 4, 5, 3, 1, 6};

    bubblesort(&x[0], &x[8]);

    std::cout << "Sorted array: ";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
