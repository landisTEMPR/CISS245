#include <iostream>
#include "Time.h"


int main()
{
    Time t0 = {9, 10, 0};
    time_Print(t0);
    time_Print(&t0);
    
    time_add_one_Sec(t0);
    time_Print(t0);
    time_add_one_Sec(&t0);
    time_Print(t0);

    
    // Time t1 = {9, 10, 1};
    // bool b = time_Equals(t0, t1);
    // std::cout << b << std::endl;

    // while (!time_Equals(t0, t1))
    // {
    //     time_Print(t0);
    //     time_add_one_Sec(t0);      
    // }
    
    return 0;
}
