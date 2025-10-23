#include <iostream>


void merge(int x[], int &x_len, const int y[], int y_len, const int z[], int z_len)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < y_len && j < z_len)
    {
        if (y[i] <= z[j])
        {
            x[k] = y[i];
            ++i;
        }
        else
        {
            x[k] = z[j];
            ++j;
        }
        ++k;
    }

    while (i < y_len)
    {
        x[k] = y[i];
        ++i;
        ++k;
    }

    while (j < z_len)
    {
        x[k] = z[j];
        ++j;
        ++k;
    }

    x_len = y_len + z_len;

    return;
}


int main()
{
    int y[1024] = {0, 2, 6};
    int y_len = 3;
    int z[1024] = {0, 1, 2, 5, 7, 9};
    int z_len = 6;
    int x[1024];
    int x_len = 0;

    merge(x, x_len, y, y_len, z, z_len);

    std::cout << "Merged array: ";
    for (int i = 0; i < x_len; ++i)
    {
        std::cout << x[i] << " ";
    }
    std::cout << "\n";

    std::cout << "x_len = " << x_len << std::endl;

    return 0;
}
