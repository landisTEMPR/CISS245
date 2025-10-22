#include <iostream>
#include "Date.h"

void init(Date &date, int yyyy, int mm, int dd)
{
    date.yyyy_ = yyyy;
    date.mm_ = mm;
    date.dd_ = dd;
}
void print(const Date &date)
{
    std::cout << date.yyyy_ << '-'
              << date.mm_ << '-'
              << date.dd_ << '\n';
}
void add_y(Date &date, int i)
{
    date.yyyy_ += i;
}
void add_m(Date &date, int i)
{
    date.mm_ += i;
    if (date.mm_ >= 13)
    {
        date.yyyy_ += date.mm_ / 12;
        date.mm_ = 1;
    }
}
void add_d(Date &date, int i)
{
    date.dd_ += i;
}
