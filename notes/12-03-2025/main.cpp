#include <iostream>


class Shape
{
public:
    virtual double area()
    {
        return 0.0;
    }
};


class Rect: public Shape
{
public:
    double area()
    {
        return w * h;
    }
    int w, h;
};


class Circle: public Shape 
{
public:
    double area()
    {
        return 3.14159 * r * r;
    }
    int r;
};


int main()
{
    Rect r;
    r.w = 2;
    r.h = 3;
    std::cout << r.area() << '\n';

    Circle c;
    c.r = 5;
    std::cout << c.area() << '\n';

    Shape * shape[2];
    shape[0] = &r;
    shape[1] = &c;

    for (int i = 0; i < 2; ++i)
    {
        std::cout << shape[i]->area() << '\n';
    }

    return 0;
}
