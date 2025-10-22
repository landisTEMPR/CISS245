#include <iostream>
#include "Date.h"

void Date::init(int yyyy, int mm, int dd)
{
    yyyy_ = yyyy;
    mm_ = mm;
    dd_ = dd;
}


void Date::print()
{
    std::cout << yyyy_ << '-'
              << mm_ << '-'
              << dd_ << '\n';
}


void Date::add_y(int i)
{
    yyyy_ += i;
}


void Date::add_m(int i)
{
    mm_ += i;
    if (mm_ >= 13)
    {
        yyyy_ += mm_ / 12;
        mm_ = 1;
    }
}


void Date::add_d(int i)
{
    dd_ += i;
}


void Date::add_m_d(int dm, int dd)
{
    add_m(dm);
    // mm_ += dm;
    add_d(dd);
    // dd_ += dd;
}
