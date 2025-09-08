#include <iostream>


void print(int x[], int start, int end);
void println(int x[], int start, int end);

int main()
{
    int x[] = {5, 3, 1, 2, 4, 6};
    print(x, 0, 4);

    return 0;
}


void print(int x[], int start, int end)
{
    std::cout << '{';
    for (int i = start; i < end; ++i)
    {
        std::cout << x[i];
        if (i < end - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << '}';
    
}

