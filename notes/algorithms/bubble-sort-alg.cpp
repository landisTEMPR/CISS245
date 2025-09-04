#include <iostream>


// broken rn

// notation: x[2], x[3], x[4] .. x[2..4]
// bubllesort of x[0 .. n - 1]
// 
// for i = n - 2, n - 3, ......, 0
//     for j = 0, ....., i
//        if (x[j] > x[x + 1])
//             swar x[j] and x[j + 1]    
void bubblesort(int x[], int start, int end)
{
    for (int i = end; i >= start; --i)
    {
        for (int j = start; j <= i; ++j)
        {
            if (x[j] > x[j + 1])
                {
                    int t = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = t;
                }
        }
    }
}


void initialize(int x[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> x[i];
        std::cout << std::endl;
        std::cout << x[i] << ' ';
        std::cout << std::endl;
    }
}


void print(int x[], int size)
{
    std::cout << '{';
    for (int i = 0; i <= size; ++i)
    {
        std::cout << x[i];
        if (i < size)
        {
            std::cout << ", ";
        }
    }
    std::cout << '}' << std::endl;
}

    
int main()
{
    int size = 0;
    std::cin >> size;
    int x[] = {size};
    initialize(x, size);
    print(x, size);
    int start, end;
    std::cin >> start >> end;
    bubblesort(x, start, end);
    print(x, size);
}
