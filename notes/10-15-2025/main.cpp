#include <iostream>

int main()
{
    char x = 'a';
    double y = 2.718;
    bool z = false;
    int w[] = {2, 5, 3, 7};

    char *c = &x;
    double *g = &y;
    bool *h = &z;
    int *d = &w[3];

    std::cout << *c << ' ' << *g << ' ' << *h << ' ' << *d << '\n';
    return 0;
}
