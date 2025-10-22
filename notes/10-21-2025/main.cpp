#include <iostream>
#include "Date.h"

int main()
{
    Date today;
    init(today, 2025, 10, 22);
    print(today);
    add_d(today, 1);
    print(today);
    add_m(today, 1);
    print(today);
    add_y(today, 1);
    print(today);

    Date yesterday;
    init(yesterday, 2025, 10, 21);
    print(yesterday);
    return 0;
}











