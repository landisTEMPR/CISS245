#include <iostream>

int f(int x)
{
    std::cout << "entering f() with x = " << x << std::endl;

    if (x == 0)
    {
        return 0;
    }
    else
    {
        return f(x - 1);
    }
}

int main()
{
    int x = f(3);
    std::cout << "main() .... x = " << x << std::endl;
    return 0;
}
