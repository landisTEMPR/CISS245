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


void print(const Robot & robots)
{
    /* for (int i = 0; i < 3; ++i)
    {
        std::cout << robots[i] << '\n';
    }
    */
    
}

void move_north(Robot & r)
{
    if (r.energylevel == 0) return;
    r.y -= 1;
}

void move_south(Robot & r)
{
    if (r.energylevel == 0) return;
    r.y += 1;
}

void move_east(Robot & r)
{
    if (r.energylevel == 0) return;
    r.x += 1;
}

void move_west(Robot & r)
{
    if (r.energylevel == 0) return;
    r.x -= 1;
}

void inc_energylevel(Robot &r, int amount)
{
    r.energylevel += amount;
}

void dec_robot_energy(Robot &r, int amount)
{
    if (r.energylevel > 0)
    {
        r.energylevel -= amount;
    }
}


void recharge_robots(char world[10][10], Robot robots[], PowerStation ps[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int dx = abs(robots[i].x - ps[j].x);
            int dy = abs(robots[i].y - ps[j].y);

            // If robot is adjacent to a power station
            if ((dx <= 1 && dy <= 1) && ps[j].energylevel >= 10)
            {
                dec_robot_energy(robots[i], 1);
                std::cout << "Robot at (" << robots[i].x << ", " << robots[i].y
                          << ") recharged from PowerStation (" << ps[j].x << ", " << ps[j].y << ")!\n";
            }
        }
    }
}

void place_robots(char world[10][10], Robot robots[], int n)
{
    const char ROBOTNAMES[3] = { 'C', 'D', 'R' };
    const int ENERGYLEVEL = 100;
    
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        
        do
        {
            x = rand() % 10;
            y = rand() % 10;
        } 
        while (world[y][x] != ' ');

        init(robots[i], ROBOTNAMES[i], x, y, ENERGYLEVEL);
        
        world[y][x] = ROBOTNAMES[i];
    }
}

bool found_gold(const char world[10][10], const Robot robots[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int x = robots[i].x;
        int y = robots[i].y;

        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0)
                    continue;

                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10)
                {
                    if (world[newY][newX] == 'G')
                    {
                        std::cout << "Robot " << robots[i].name
                                  << " found gold at (" << newX << ", " << newY << ")!\n";
                        return true;
                    }
                }
            }
        }
    }

    return false;
}


void move_robots(char world[10][10], Robot robots[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int move = rand() % 4;

        // Clear old position
        world[robots[i].y][robots[i].x] = ' ';

        switch (move)
        {
            case 0:
                move_north(robots[i]);
                break;
            case 1:
                move_east(robots[i]);
                break;
            case 2:
                move_south(robots[i]);
                break;
            case 3:
                move_west(robots[i]);
                break;
        }

        // Keep robots in bounds
        if (robots[i].x < 0)
        {
            robots[i].x = 0;
        }
        if (robots[i].x > 9)
        {
            robots[i].x = 9;
        }
        if (robots[i].y < 0)
        {
            robots[i].y = 0;
        }
        if (robots[i].y > 9)
        {
            robots[i].y = 9;
        }

        dec_robot_energy(robots[i], 1);

        world[robots[i].y][robots[i].x] = robots[i].name;
    }
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


