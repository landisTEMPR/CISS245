#ifndef TIME_H
#define TIME_H

#include <iostream>

struct Time
{
    int hh, mm, ss;
};

Time Time_get(int hh, int mm, int ss);
void Time_print(const Time & t0);
void Time_print(const Time * t0);
void Time_add_one_sec(Time & t0);
void Time_add_one_sec(Time * t0);
bool Time_equals(const Time & t0, const Time & t1);
bool Time_equals(const Time * t0, const Time * t1);
bool operator==(const Time & t0, const Time & t1);
bool operator!=(const Time & t0, const Time & t1);
void operator+=(Time & t0, const Time & t1);
std::ostream & operator<<(std::ostream &, const Time &);

#endif
