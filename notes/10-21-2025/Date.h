#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
public:
    Date(int yyyy = 1970, int mm = 1, int dd = 1);

    void init(int yyyy, int mm, int dd);
    void print() const;

    void add_y(int years);
    void add_m(int months);          // handles overflow/underflow of months
    void add_d(int days);            // simple day offset (no normalization by month length)
    void add_m_d(int months, int days);

    int get_year() const;
    void set_year(int yyyy);

    int get_month() const;
    void set_month(int mm);

    int get_day() const;
    void set_day(int dd);

private:
    int yyyy_;
    int mm_;
    int dd_;
};

std::ostream & operator<<(std::ostream & os, const Date & date);

#endif // DATE_H
