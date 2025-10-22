#include <iostream>
#include "Date.h"

int main()
{
    Date today;
    today.init(2025, 10, 22);
    today.print();
    today.add_d(1);
    today.add_m(1);
    today.add_y(1);
    today.print();

    Date yesterday;
    yesterday.init(2025, 10, 21);
    yesterday.print();

    today.add_m_d(5, 5);
    today.print();
    

    
    return 0;
}











