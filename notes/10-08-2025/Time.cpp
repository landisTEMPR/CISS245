#include <iostream>
#include <iomanip>
#include "Time.h"


// Or Time_constructor(int hh, int mm, int ss)
// Or Time_ctor(int hh, int mm, int ss)
Time Time_get(int hh, int mm, int ss)
{
    Time ret = {hh, mm, ss};
    return ret;
}


void Time_print(const Time& t0)
{
    std::cout << std::setfill('0') << std::setw(2) << t0.hh << ':'
          << std::setfill('0') << std::setw(2) << t0.mm << ':'
          << std::setfill('0') << std::setw(2) << t0.ss << '\n';

    return;
}


void Time_print(const Time* t0)
{
    std::cout << std::setfill('0') << std::setw(2) << t0->hh << ':'
          << std::setfill('0') << std::setw(2) << t0->mm << ':'
          << std::setfill('0') << std::setw(2) << t0->ss << '\n';
    return;
}


void Time_add_one_sec(Time& t0)
{
    ++t0.ss;
    if (t0.ss == 60)
    {
        t0.ss = 0;
        ++t0.mm;
        
    }
    if (t0.mm == 60)
    {
        t0.mm = 0;
        ++t0.hh;
    }
    if (t0.hh == 24)
    {
        t0.hh = 0;
    }

    return;
}


void Time_add_one_sec(Time* t0)
{
    ++t0->ss;

    return;
}


bool Time_equals(const Time& t0, const Time& t1)
{

    return(t0.hh == t1.hh && t0.mm == t1.mm && t0.ss == t1.ss);
}


bool Time_equals(const Time* t0, const Time* t1)
{
    return(t1->hh == t1->hh && t0->mm == t1->mm && t0->ss == t1->ss);
}
