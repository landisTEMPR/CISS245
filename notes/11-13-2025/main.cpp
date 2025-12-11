#include <iostream>


int fib(int n)
{
    if (n <= 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}


void hanoi(int n, char from, char helper, char to)
{
    if (n == 1)
    {
        std::cout << from << " ------> " << to << '\n';
    }
    else
    {
        hanoi(n - 1, from, to, helper);
        hanoi(1, from, helper, to);
        hanoi(n - 1, helper, from, to);
    }
}

int main()
{
    // for (int n = 0; n < 10; ++n)
    // {
    //     std::cout << n << ' ' << fib(n) << '\n';
    // }

    hanoi(4, 'A', 'B', 'C');

    return 0;
}
