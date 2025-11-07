/************************************************************************
File : main.cpp
Author : Brysen Landis
************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Robot.h"
#include "World.h"
#include "PowerStation.h"
#include "Gold.h"

void test_print()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    print(r);
    
}

void test_move_north()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_north(r);
    print(r);
    
}

void test_move_south()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_south(r);
    print(r);
    
}

void test_move_east()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_east(r);
    print(r);
    
}

void test_move_west()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    move_west(r);
    print(r);
    
}

void test_inc_energylevel()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    int i;
    std::cin >> i;
    inc_energylevel(r, i);
    print(r);
    
}

void test_dec_energylevel()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    int i;
    std::cin >> i;
    dec_energylevel(r, i);
    print(r);
    
}

void test_init_and_print_world()
{
    char world[10][10];
    init(world);
    print(world);
}

void test_set()
{
    char world[10][10];
    init(world);
    print(world);
    set(world);
    print(world);
}

void test_power_station()
{
    int x = 0, y = 0;
    int energylevel;
    std::cin >> y >> x >> energylevel;
    PowerStation ps;
    init(ps, y, x, energylevel);
    print(ps);
}

void test_dec_ps_energylevel()
{
    int x = 0, y = 0;
    int energylevel;
    std::cin >> y >> x >> energylevel;
    PowerStation ps;
    init(ps, y, x, energylevel);
    print(ps);
    int d;
    std::cin >> d;
    dec_energylevel(ps, d);
    print(ps);
}

int main()
{
    int seed;
    std::cin >> seed;
    srand(seed);

    const int TIME_LIMIT = 100;
    int time = TIME_LIMIT;

    char world[10][10];
    Robot robots[3];  // c, d, r
    PowerStation ps[3];

    init(world);
    place_ps(world, ps, 3);
    // place_robots(world, robots, 3);
    init_gold(world, 3);
    print(world);
    /*
    while (time > 0)
    {
        if (found_gold(world, robots, 3))
        {
            std::cout << "A robot found the gold! Game over.\n";
            break;
        }

        move_robots(world, robots, 3);
        recharge_robots(world, robots, 3);

        --time;
    }

    if (time == 0)
        std::cout << "Time’s up! No robot found the gold.\n";

    print(world);
    */
    return 0;
}

