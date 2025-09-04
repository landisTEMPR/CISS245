#include <iostream>
#include <cmath>


int min(int x, int y);


int GCD(int m, int n)
{
    int g = 1;
    for (int i = min(m, n); i >= 1; --i)
    {
        if (m % i == 0 && n % i == 0)
        {
            g = i;
            break;
        }
    }
    return g;
}


int min(int x, int y)
{
    return (x <= y ? x : y);
}


void add_fraction(int n0, int d0, int n1, int d1, int & n2, int & d2)
{
    // compute the fraction addition
    n2 = n0 * d1 + d0 * n1;
    d2 = d0 * d1;
    
    // compute the GCD of n2, d2, store in g
    int g = GCD(n2, d2);
    
    // simplify the fraction
    n2 /= g;
    d2 /= g;
}


int main()
{
    int n0, d0; // fraction numerators and denominators
    int n1, d1;
    std::cin >> n0 >> d0 >> n1 >> d1;

    int n2, d2; // final fraction variables
    add_fraction(n0, d0, n1, d1, n2, d2);
    
    std::cout << n0 << '/' << d0
              << " + "
              << n1 << '/' << d1
              << " = "
              << n2 << '/' << d2
              << '\n';
    
    return 0;
}
