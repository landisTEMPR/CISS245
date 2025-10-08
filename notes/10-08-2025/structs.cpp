#include <iostream>


struct Time
{
    int hh;
    int mm;
    int ss;
};


void time_Print(const Time& t)
{
    std::cout << t.hh << ':' << t.mm << ':' << t.ss << '\n';
    
    return;
}


int main()
{
    Time t;
    t.hh = 9;
    t.mm = 10;
    t.ss = 0;
    time_Print(t);

    Time t1 = {7, 15, 45};
    time_Print(t1);
    return 0;
}
