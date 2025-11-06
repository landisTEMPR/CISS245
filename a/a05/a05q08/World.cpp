/*********************************************************************
File : World.cpp
Author: Brysen Landis
Implementation of world.h.
*********************************************************************/

#include <iostream>
#include "World.h"


void init(char world[10][10])
{
    for(int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            world[j][i] = '*';
        }
    }
}

void print(char world[10][10])
{
    for (int i = 0; i < 13; ++i)
    {
        if (i == 0)
            {
                std::cout << "   ";
                for (int j = 0; j < 10; ++j)
                {
                    std::cout << j;
                }
                std::cout << '\n';
            }

        if (i == 1)
            {
                std::cout << "  ";
                for (int j = 0; j < 12; ++j)
                {
                    std::cout << 'X';
                }
                std::cout << '\n';
            }
        if (i > 1 && i < 12)
        {
            std::cout << i - 2 << " X";
            for (int j = 0; j < 10; ++j)
            {
                std::cout << world[j][i];
            }
            std::cout << '\n';
        }
        
    }
}
