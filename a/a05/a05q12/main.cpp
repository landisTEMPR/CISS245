/************************************************************************
File : main.cpp
Author : Brysen Landis
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Robot.h"
#include "World.h"
#include "PowerStation.h"
#include "Gold.h"

int main()
{
    int timer = 100;
    char world[10][10];
    Robot robots[3];
    PowerStation ps[3]; // Add power stations

    // int seed;
    // std::cin >> seed;
    
    srand((unsigned int) time(NULL));

    init(world);
    place_robots(world, robots, 3);
    place_ps(world, ps, 3);
    init_gold(world, 1);

    print(world);

    while (timer > 0)
    {
        std::cout << "Time: " << timer << '\n';

        // Check if any robot found gold
        if (found_gold(world, robots, 3))
        {
            std::cout << "A robot found gold! Game over.\n";
            break;
        }

        // Move robots randomly
        move_robots(world, robots, 3);

        // Recharge robots if near a power station
        recharge_robots(world, robots, ps, 3);

        // Decrease time and print updated world
        --timer;
        print(world);
    }

    if (timer == 0)
        std::cout << "Time’s up! No robot found the gold.\n";

    print(world);

    return 0;
}
