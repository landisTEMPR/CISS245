#include <iostream>
#include <ctime>
#include <cstdlib>

// void bottom_left_tri(int n);

int main()
{
    int roll = rand() % 2;
    bool turn = roll;

    std::cout << turn << std::endl;
    
    return 0;
}
    
    // for (int i = 0; i < n; ++i)
    // {
    //     std::cout << (i % 2 == 0 ? '*' : '@'); // remember ternary operator
    //     std::cout << std::endl;                // for simple if else
    // }

    // -----------------------------------------------------------------------
    
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)            // asci art block
    //     {
    //         std::cout << " * ";
    //     }
        
    //     std::cout << std::endl;
    // }

    // -----------------------------------------------------------------------

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n - i; ++j)          // asci pyramid
    //     {
    //         std::cout << '*';
    //     }
    //     std::cout << std::endl;
    // }

    // -----------------------------------------------------------------------

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n - i; ++j)           // asci angle thingy
    //     {
    //         std::cout << ' ';
    //     }
    //     std::cout << '*';
    //     std::cout << std::endl;
    // }
    // void bottom_left_tri(int n)
    // {
    //     for (int i = 0; i < n; ++i)
    //     {
    //         int nstars = i + 1;
    //         int nspaces = n - (i + 1);

    //         for (int j = 0; j < nspaces; ++j)
    //         {
    //             std::cout << ' ';
    //         }
    //         for (int j = 0; j < nstars; ++j)
    //         {
    //             std::cout << '*';
    //         }

    //         std::cout << std::endl;
    //     }


