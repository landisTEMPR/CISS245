/*********************************************************************
File : World.cpp
Author: Brysen Landis
Implementation of world.h.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include "World.h"

void init(char world[10][10])
{
    // Step 1: clear world
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            world[i][j] = ' ';
        }
    }

    bool valid = false;

    while (!valid)
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                world[i][j] = ' ';
            }
        }

        valid = true;

        for (int wall = 0; wall < 2; ++wall)
        {
            int x = rand() % 10;
            int y = rand() % 10;
            int dir = rand() % 4;
            int dx = 0, dy = 0;

            if (dir == 0)
            {
                dy = -1; // north
            }
            else if (dir == 1)
            {
                dy = 1; // south
            }
            else if (dir == 2)
            {
                dx = 1; // east
            }
            else if (dir == 3)
            {
                dx = -1; // west
            }

            // Check if wall fits in bounds
            int endX = x + dx * 3;
            int endY = y + dy * 3;

            if (endX < 0 || endX > 9 || endY < 0 || endY > 9)
            {
                valid = false;
                break; // restart everything
            }

            // Check overlap if it's the second wall
            for (int i = 0; i < 4 && valid; ++i)
            {
                int newX = x + dx * i;
                int newY = y + dy * i;
                if (world[newY][newX] == 'X')
                {
                    valid = false;
                }
            }

            if (!valid)
                break;

            // Place wall
            for (int i = 0; i < 4; ++i)
            {
                int newX = x + dx * i;
                int newY = y + dy * i;
                world[newY][newX] = 'X';
            }
        }
    }
}

void print(char world[10][10])
{
    std::cout << "   0123456789\n";
    std::cout << "  XXXXXXXXXXXX\n";

    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " X";
        for (int j = 0; j < 10; ++j)
        {
            std::cout << world[i][j];
        }
        std::cout << "X\n";
    }

    std::cout << "  XXXXXXXXXXXX\n";
}
