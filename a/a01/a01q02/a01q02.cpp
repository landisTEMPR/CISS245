#include <iostream>


void draw_rising_hills(int n)
{
    if (n == 0)
    {
        return;
    }
    
    for (int i = 0; i < n; ++i)
    {
        int nstars = (i + 1) * 2;
        int nspaces = (n - (i + 1)) * 2 ;

        for (int j = 0; j < nspaces; ++j)
        {
            std::cout << ' ';
        }
        if (i != 0)
        {
            for (int j = 0; j < nstars; ++j)
            {
                std::cout << '*';
            }
        }
        else
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}


int main()
{
    int n;
    std::cin >> n;
    draw_rising_hills(n);
    return 0;
}
