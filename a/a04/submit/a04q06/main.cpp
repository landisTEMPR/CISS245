// File : a04q06.cpp
// Author : Brysen Landis
#include <iostream>

int opendoors(int n)
{
    bool *open;
    int count = 0;
    open = new bool[n];
    
    for (int i = 0; i < n; ++i)
    {
        open[i] = false;
    }
    
    int step = 1;
    bool ltr = true;
    
    while (true)
    {
        int dA = 0;
        
        if (ltr == true)
        {
            for (int i = 0; i < n; i += step)
            {
                ++dA;
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; i -= step)
            {
                ++dA;
            }
        }
        
        if (dA <= 1)
        {
            break;
        }
        
        if (ltr == true)
        {
            for (int i = 0; i < n; i += step)
            {
                open[i] = true;
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; i -= step)
            {
                open[i] = false;
            }
        }
        
        ++step;
        ltr = !ltr;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (open[i] == true)
        {
            ++count;
        }
    }
    
    delete[] open;
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << opendoors(n) << std::endl;
    return 0;
}
