#include <iostream>

void print(int x[3], int x_size)
{
    for (int i = 0; i < x_size; ++i)
    {
        std::cout << x[i] << ' ';
    }
}

void print_from(int x[], int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        std::cout << x[i] << ' ';
    }
}

double sum(double x[], int x_size)\
{
    double s = 0.0;
    for (int i = 0; i < x_size; ++i)
    {
        s += x[i];
    }
    
    return s;
}

double product(double x[], int x_size)
{
    double p = 1;
    for (int i = 1; i < x_size; ++i)
    {
        p *= x[i];
    }

    return p;
}

double min(double x[], int x_size)
{
    double m;
    for (int i = 0; i < x_size; ++i)
    {
        m = x[i];
        if (x[i] < m)
        {
            m = x[i];
        }
    }

    return m;
}



int main()
{
    int a[] = {1, 2, 3};
    print(a, 3);
    std::cout << "\n\n";
    
    int b[] = {5, 6, 7, 8, 9};
    print(b, 5);
    std::cout << "\n\n";
    
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_from(c, 0, 6);
    std::cout << "\n\n";

    double d[] = {1.1, 2.2, 3.3};
    std::cout << sum(d, 1) << std::endl;
    std::cout << sum(d, 2) << std::endl;
    std::cout << sum(d, 3) << std::endl;
    std::cout << "\n\n";

    double e[] = {1, 2, 3};
    std::cout << product(e, 1) << '\n';
    std::cout << product(e, 2) << '\n';
    std::cout << product(e, 3) << '\n';
    std::cout << '\n';

    double f[] = {1.2, -2.5, -7.5, 0.0};
    std::cout << min(f, 1) << std::endl; // 1.2
    std::cout << min(f, 2) << std::endl; // -2.5
    std::cout << min(f, 3) << std::endl; // -7.5
    std::cout << min(f, 4) << std::endl; // -7.5
    return 0;
}
