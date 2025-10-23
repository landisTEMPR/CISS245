// File : a04q04.cpp
// Author : Brysen Landis

#include <iostream>

void filter(int x[], int n)
{
    int *p;

    if (n <= 0)
        return;

    p = new int[n];

    if (n == 1)
    {
        p[0] = x[0];
    }
    else if (n == 2)
    {
        p[0] = x[0];
        p[1] = x[1];
    }
    else
    {
        p[0] = x[0];

        for (int i = 1; i <= n - 2; ++i)
        {
            p[i] = (x[i - 1] + x[i] + x[i + 1]) / 3;
        }

        p[n - 1] = x[n - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        x[i] = p[i];
    }

    delete[] p;
    return;
}

int main()
{
    int x[1024];
    int n = 0;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }

    filter(x, n);

    for (int i = 0; i < n; ++i)
    {
        std::cout << x[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
