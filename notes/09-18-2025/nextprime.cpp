#include <iostream>
#include <cmath>

bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else
    {
        for (int d = 2; d <= sqrt(n); ++d)
        {
            if (n % d == 0) return false;
        }
        return true;
    }
}

void nextprime(int & x)
{
    ++x;
    while (!isprime(x))
    {
        ++x;
    }
    return;
}

    
int main()
{ 
    int x = 0;

    for (int i = 0; i < 10; ++i)
    {
        nextprime(x);
        std::cout << x << '\n';
    }


    return 0;
}
