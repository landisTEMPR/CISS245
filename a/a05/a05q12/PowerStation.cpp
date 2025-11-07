/*********************************************************************
File : PowerStation.cpp
Author: Brysen Landis
*********************************************************************/

#include <iostream>
#include "PowerStation.h"

void init(PowerStation & powerstation, int y, int x, int energylevel)
{
    powerstation.x = x;
    powerstation.y = y;
    powerstation.energylevel = energylevel;   
}

void print(const PowerStation & powerstation)
{
    std::cout << powerstation << '\n';
}

void dec_energylevel(PowerStation & powerstation, int d)
{
    powerstation.energylevel -= d;
}

void place_ps(char world[10][10], PowerStation ps[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        int x, y;
        bool placed = false;

        while (!placed)
        {
            x = rand() % 10;
            y = rand() % 10;
            
            if (world[y][x] == ' ')
            {
                init(ps[i], y, x, 50); 
                world[y][x] = 'P';
                placed = true;
            }
        }
    }
}

std::ostream & operator<<(std::ostream & cout, const PowerStation & powerstation)
{
    cout << "<PowerStation: x=" << powerstation.x
         << ", y=" << powerstation.y
         << ", energylevel=" << powerstation.energylevel
         << '>';

    return cout;
}
