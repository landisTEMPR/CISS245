/************************************************************************
File : Gold.cpp
Author : Brysen Landis
************************************************************************/

#include <iostream>
#include "Gold.h"
#include "World.h"

void init_gold(char world[10][10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        bool placed = false;
        int x, y;

        while (!placed)
        {
            x = rand() % 10;
            y = rand() % 10;

            if (world[y][x] == ' ')
            {
                world[y][x] = 'G';
                placed = true;
            }
        }
    }
}


