#include <iostream>
#include "Date.h"

int main()
{
    Date today(2025, 10, 22);
    today.print();

    Date yesterday(2025, 10, 21);
    yesterday.print();

    today.set_year(2037);
    std::cout << "Today: " << today << '\n';

    // Demonstrate month overflow and underflow
    Date d1(2025, 12, 15);
    std::cout << "d1: " << d1 << '\n';
    d1.add_m(1);                 // becomes 2026-1-15
    std::cout << "d1 after +1 month: " << d1 << '\n';

    Date d2(2025, 1, 15);
    std::cout << "d2: " << d2 << '\n';
    d2.add_m(-2);                // becomes 2024-11-15
    std::cout << "d2 after -2 months: " << d2 << '\n';

    return 0;
}
