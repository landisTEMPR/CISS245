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

std::ostream & operator<<(std::ostream & cout, const PowerStation & powerstation)
{
    cout << "<PowerStation: x=" << powerstation.x
         << ", y=" << powerstation.y
         << ", energylevel=" << powerstation.energylevel
         << '>';

    return cout;
}
