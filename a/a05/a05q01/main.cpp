/************************************************************************
File : main.cpp
Author : Brysen Landis
************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Robot.h"

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

int main()
{
    int seed;
    std::cin >> seed;
    srand(seed);

    int option = 0;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_print();
            break;
        case 2:
            test_move_north();
            break;
    }
    return 0;
}
