// Pass by reference practice

#include <iostream>


int main()
{
    int i = 42;
    int & j = i;

    std::cout << i << ' ' << j << '\n';

    i = 0;
    std::cout << i << ' ' << j << '\n';
    
    j = 5;
    std::cout << i << ' ' << j << '\n';

    int & k = j;
    std::cout << i << ' ' << j << ' ' << k << '\n';

    k = 8;
    std::cout << i << ' ' << j << ' ' << k << '\n';

    return 0;
}
