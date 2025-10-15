#include <iostream>


void print(const int x[], int len)
{
    std::cout << '{';
    for (int i = 0; i < len; ++i)
    {
        std::cout << x[i];
    }
    std::cout << '}' << '\n';
}


void concat(int x[], int &x_len, const int y[], const int y_len)
{
    for (int i = 0; i < y_len; ++i)
    {
        x[x_len + i] = y[i];
    }

    x_len += y_len;

    return;
}


int main()
{
    int x[] = {2, 4, 6, 8, 10};
    int x_len = 3;
    int y[] = {5, 7, 9, 11, 45};
    int y_len = 4;

    print(x, x_len);
    concat(x, x_len, y, y_len);
    print(x, x_len);

    return 0;
}
