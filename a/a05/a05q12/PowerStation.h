/*********************************************************************
File : PowerStation.h
Author: Brysen Landis
*********************************************************************/

#ifndef POWERSTATION_H
#define POWERSTATION_H

#include <iostream>

struct PowerStation
{
    int x, y;
    int energylevel;
};

void init(PowerStation & powerstation, int y, int x, int energylevel);
void print(const PowerStation & powerstation);
void drain_power(PowerStation & powerstation, int d);
void place_ps(char world[10][10], PowerStation ps[], int count);
std::ostream & operator<<(std::ostream &, const PowerStation &);

#endif
