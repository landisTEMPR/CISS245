#include <iostream>
#include "Time.h"


void time_Print(const Time& t)
{
    std::cout << t.hh << ':'
              << t.mm << ':'
              << t.ss << '\n';
    return;
}


void time_Print(const Time* t)
{
    std::cout << t->hh << ':'
              << t->mm << ':'
              << t->ss << '\n';
    return;
}


void time_add_one_Sec(Time& t)
{
    ++t.ss; 
}


void time_add_one_Sec(Time* t)
{
    ++t->ss;
}


bool time_Equals(const Time& t0, const Time& t1);


bool time_Equals(const Time* t0, const Time* t1);
