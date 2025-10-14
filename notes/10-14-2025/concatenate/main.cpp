#include <iostream>


void array_print(const int x[], int len)
{
    std::cout << "{";
    for (int i = 0; i < len; ++i)
    {
        std::cout << x[i];
    }
    std::cout << "}" << '\n';
}

void array_concat(int x[], int &x_len, int y[], int y_len)
{
    for (int i = 0; i < y_len; ++i)
    {
        x[x_len + i] = y[i];
    }
    x_len += y_len;
}

int main()
{
    int x[1024] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    int x_len = 4;
    int y[1024] = { 2, 4, 8, 16, 32, 64, 128, 256 };
    int y_len = 3;
    array_print(x, x_len);
    array_concat(x, x_len, y, y_len);
    array_print(x, x_len);
    
    return 0;
}
