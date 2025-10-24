#include "Date.h"

// constructor of Date class
Date::Date(int yyyy, int mm, int dd)
    : yyyy_(yyyy), mm_(mm), dd_(dd)
{
}

// initialize or re-initialize
void Date::init(int yyyy, int mm, int dd)
{
    yyyy_ = yyyy;
    mm_ = mm;
    dd_ = dd;
}

void Date::print() const
{
    std::cout << yyyy_ << '-' << mm_ << '-' << dd_ << '\n';
}

void Date::add_y(int years)
{
    yyyy_ += years;
}

// Robust month add: handles positive and negative month offsets.
// Keeps month in range 1..12 and adjusts year accordingly.
void Date::add_m(int months)
{
    if (months == 0)
    {
        return;
    }

    // Convert current (year,month) to a continuous month index where month 1 of year 0 is index 0
    // Use (yyyy_ * 12) + (mm_ - 1)
    int totalMonths = yyyy_ * 12 + (mm_ - 1) + months;

    // Compute new year and month
    // Note: integer division handles negative values correctly for our purposes if we use floor-like division.
    // In C++ integer division truncates toward zero, so we adjust for negative totals.
    if (totalMonths >= 0)
    {
        yyyy_ = totalMonths / 12;
        mm_ = (totalMonths % 12) + 1;
    }
    else
    {
        // For negative totalMonths, adjust to get proper floor division
        int years = (totalMonths + 1) / 12 - 1;
        yyyy_ = years;
        mm_ = totalMonths - (years * 12) + 1;
    }
}

void Date::add_d(int days)
{
    // Simple addition of days without month/year normalization.
    // (If you want proper calendar-aware behavior, we can implement day normalization later.)
    dd_ += days;
}

void Date::add_m_d(int months, int days)
{
    add_m(months);
    add_d(days);
}

int Date::get_year() const
{
    return yyyy_;
}

void Date::set_year(int yyyy)
{
    yyyy_ = yyyy;
}

int Date::get_month() const
{
    return mm_;
}

void Date::set_month(int mm)
{
    mm_ = mm;
}

int Date::get_day() const
{
    return dd_;
}

void Date::set_day(int dd)
{
    dd_ = dd;
}

std::ostream & operator<<(std::ostream & os, const Date & date)
{
    os << date.get_year() << '-' << date.get_month() << '-' << date.get_day();
    return os;
}
