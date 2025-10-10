#include <iostream>
#include <chrono>
#include <thread>
#include "Time.h"

int main()
{
    std::cout << "t0:\n";
    Time t0 = Time_get(9, 10, 0);
    Time_print(&t0);

    //Time t1;
    // dont do this
    // t1.hh = t0.hh;
    // t1.mm = t0.mm;
    // t1.ss = t0.ss;x
    // do this to copy all the values of
    // a struct over.
    //t1 = t0;
    // std::cout << "t1:\n";
    //Time_print(t1);

    Time t1 = Time_get(9, 11, 15);
    std::cout << "t1:\n";
    Time_print(t1);
    bool b = Time_equals(t0, t1);
    std::cout << b << '\n';
    Time_equals(&t0, &t1);
    std::cout << b << '\n';

    while (!Time_equals(t0, t1))
    {
        system("clear");
        Time_print(t0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Time_add_one_sec(t0);
    }

    // while (t0 == t1) // <<< same as operator==(t0, t2)

    return 0;
}
