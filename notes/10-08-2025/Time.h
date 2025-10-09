#ifndef TIME_H
#define TIME_H


struct Time
{
    int hh;
    int mm;
    int ss;
};


void time_Print(const Time& t);
void time_Print(const Time* t);
void time_add_one_Sec(Time& t0);
void time_add_one_Sec(Time* t0);
bool time_Equals(const Time& t0, const Time& t1);
bool time_Equals(const Time* t0, const Time* t1);

#endif
