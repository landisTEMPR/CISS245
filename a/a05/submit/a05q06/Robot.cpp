/************************************************************************
File : Robot.cpp
Author : Brysen Landis
************************************************************************/

#include <iostream>
#include "Robot.h"

void init(Robot & r, char name, int x, int y, int energylevel)
{
    r.name = name;
    r.x = x;
    r.y = y;
    r.energylevel = energylevel;
}


void print(const Robot & robot)
{
    std::cout << robot << '\n';
    
}

void move_north(Robot & r)
{
    r.y -= 1;
}

void move_south(Robot & r)
{
    r.y += 1;
}

void move_east(Robot & r)
{
    r.x += 1;
}

void move_west(Robot & r)
{
    r.x -= 1;
}

void inc_energylevel(Robot & r, int i)
{
    r.energylevel += i;
}



std::ostream & operator<<(std::ostream & cout, const Robot & robot)
{
    cout << "<Robot: name=" << robot.name
         << ", x=" << robot.x
         << ", y=" << robot.y
         << ", energylevel=" << robot.energylevel
         << '>';

    return cout;
}


