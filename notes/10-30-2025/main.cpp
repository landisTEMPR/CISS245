#include <iostream>

class Time
{
public:
    //Time();
    ~Time();
    Time(int, int, int);
private:
    int hh_, mm_, ss_;
};

//Time::Time()


Time::Time(int hh, int mm, int ss)
           : hh_(hh), mm_(mm), ss_(ss)
{}

Time::~Time()
{}

int main()
{

    Time t0;

    return 0;
}
