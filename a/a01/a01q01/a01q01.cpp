// Name: Brysen Landis
// File: a01q01.cpp

#include <iostream>

void draw_spiral(int n)
{
    int total_lines = 4 * n + 1;
    int mid = 2 * n + 1;

    for (int i = 1; i <= total_lines; ++i)
    {
        if (i % 2 == 1) // Odd rows
        {
            if (i <= mid)
            {
                // Top half + middle
                int t    = (i - 1) / 2;          // 0..n
                int lead = t;
                int m    = 6 * (n - t) + 2;      // dash count

                for (int k = 0; k < lead; ++k) std::cout << "| ";
                std::cout << '+';
                for (int k = 0; k < m;    ++k) std::cout << '-';
                std::cout << '+';
                for (int k = 0; k < lead; ++k) std::cout << " |";
                std::cout << '\n';
            }
            else
            {
                // Bottom half odd rows
                int j    = (i - mid) / 2;        // 0..n-1
                int lead = n - j;
                int m    = 6 * (j + 1) - 1;      // 5, 11, 17, ...

                for (int k = 0; k < lead; ++k) std::cout << "| ";
                std::cout << '+';
                for (int k = 0; k < m;    ++k) std::cout << '-';
                std::cout << '+';
                for (int k = 0; k < lead; ++k) std::cout << " |";
                std::cout << '\n';
            }
        }
        else // Even rows
        {
            if (i < mid)
            {
                // Top half even rows
                int t    = i / 2;                // 1..n
                int lead = t - 1;
                int m    = 6 * (n - lead) + 2;

                for (int k = 0; k < lead; ++k) std::cout << "| ";
                std::cout << '|';
                for (int k = 0; k < m;    ++k) std::cout << ' ';
                std::cout << '|';
                for (int k = 0; k < lead; ++k) std::cout << " |";
                std::cout << '\n';
            }
            else
            {
                // Bottom half even rows
                int j    = (i - mid) / 2;        // 1..n
                int lead = n - j;
                int m    = 6 * j + 5;            // spaces to match next odd row

                for (int k = 0; k < lead; ++k) std::cout << "| ";
                std::cout << '|';
                for (int k = 0; k < m;    ++k) std::cout << ' ';
                std::cout << '|';
                for (int k = 0; k < lead; ++k) std::cout << " |";
                std::cout << '\n';
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    draw_spiral(n);
    return 0;
}
