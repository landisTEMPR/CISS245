#include <iostream>
#include <cmath>


int min(int x, int y)
{
    return (x <= y ? x : y);
}


int main()
{
    int n0, d0; // fraction numerators and denominators
    int n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;

    int n2, d2; // final fraction variables

    // compute the fraction addition
    n2 = n0 * d1 + d0 * n1;
    d2 = d0 * d1;

    // compute the GCD of n2, d2, store in g
    int g = 1;
    for (int i = min(n2, d2); i >= 1; --i)
    {
        if (n2 % i == 0 && d2 % i == 0)
        {
            g = i;
            break;
        }
    }

    // simplify the fraction
    n2 /= g;
    d2 /= g;
    
    std::cout << n0 << '/' << d0
              << " + "
              << n1 << '/' << d1
              << " = "
              << n2 << '/' << d2
              << '\n';
    
    return 0;
}
