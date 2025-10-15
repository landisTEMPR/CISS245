#include <iostream>
#include "Time.h"

// Or Time_constructor(int, int, int)
// Or Time_ctor(int, int, int)
Time Time_get(int hh, int mm, int ss)
{
    Time ret = {hh, mm, ss};
    return ret;
}

void Time_print(const Time & t0)
{
    std::cout << t0.hh << ':' << t0.mm << ':' << t0.ss << '\n'; 
}

void Time_print(const Time * t0)
{
    std::cout << t0->hh << ':' << t0->mm << ':' << t0->ss << '\n'; 
}

void Time_add_one_sec(Time & t0)
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
    // if t0.ss == 60, then need to increment hh set ss to 0. ...
}

void Time_add_one_sec(Time * t0)
{
    ++t0->ss;
}

bool Time_equals(const Time & t0, const Time & t1)
{
    return (t0.hh == t1.hh && t0.mm == t1.mm && t0.ss == t1.ss);
}

bool Time_equals(const Time * t0, const Time * t1)
{
    return (t0->hh == t1->hh && t0->mm == t1->mm && t0->ss == t1->ss);
}

bool operator==(const Time & t0, const Time & t1)
{
    return (t0.hh == t1.hh && t0.mm == t1.mm && t0.ss == t1.ss);
}

bool operator!=(const Time & t0, const Time & t1)
{
    return !(t0 == t1);
}

void operator+=(const Time & t0, const Time & t1)
{
    t0.ss += t1.ss;
    t0.mm += t1.mm;
    t0.hh += t1.hh;
    
    if (t0.ss >= 60)
    {
        t0.mm += t0.ss / 60;
        t0.ss %= 60;
    }
    if (t0.mm >= 60)
    {
        t0.hh += t0.mm / 60;
        t0.mm %= 60;
    }
    if (t0.hh > 23)
    {
        t0.hh %= 24;
    }
}

std::ostream & operator<<(std::ostream & cout, const Time & t0)
{
    cout << t0.hh
         << ':'
         << t0.mm
         << ':'
         << t0.ss;
    return cout;
}
