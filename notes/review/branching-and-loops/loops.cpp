#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int x;

    for (int i = 0; i < n; ++i)
    {
        std::cout << '*';
        ++x;
        for (int j = 0; j < 1; j++)
        {
            std::cout << '@';
            ++x;
        }
    }

    std::cout << x << std::endl;

    std::cout << std::endl;

    return 0;
}
