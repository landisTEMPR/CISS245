// File : a04q05
// Author : Brysen Landis

#include <iostream>
#include <cmath>

int pi(double x)
{
    if (x < 2.0) return 0; 

    double ret = 0.0;
    int count = 0;

    for (double i = 2.0; i <= x; i += 1.0)
    {
        bool isPrime = true;

        for (double d = 2.0; d <= std::sqrt(i); d += 1.0)
        {
            if (std::fmod(i, d) == 0.0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            ret += 1.0;
            count += 1;
        }
    }

    return count;
}


int main()
{
    double x;
    std::cin >> x;
    std::cout << pi(x) << '\n';
    return 0;
}
