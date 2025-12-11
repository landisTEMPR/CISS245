/**************************************************

File : Rational.cpp
Author : Brysen Landis

 *************************************************/

#include <iostream>


int GCD(int, int)
{
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    
    while(b !=0)
    {
        int tempr = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int sign(int)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}


std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
    int n = r.get_n();
    int d = r.get_d();

    if (n == 0)
    {
        cout << 0;
        return cout;
    }
    if (d < 0)
    {
        n = -n;
        d = -d;
    }
    if (d == 1)
    {
        cout << n;
    }
    else
    {
        cout << n << "/" << d;
    }
    return cout;
}


std::istream & operator>>(std::istream & cin, Rational & r)
{
    int n, d;
    cin >> n >> d;
    r = Rational(n, d);
    return cin;
}


void Rational::reduce()
{
    if (n == 0)
    {
        d = 1;
        return;
    }

    int g = GCD(n, d);

    n = n / g;
    d = d / g;

    if (d < 0)
    {
        n = -n;
        d = -d;
    }
}


void reduce(Rational & r)
{
    r.reduce();
}


bool Rational::operator==(const Rational & r) const
{
    return (n * r.d) == (d * r.n);
}


bool Rational::operator!=(const Rational & r) const
{
    return !(*this == r);
}


bool Rational::operator>(const Rational & r) const
{
    int l = n * r.d;
    int r = d * r.n;

    if ((d > 0 && r.d > 0) || d < 0 && r.d < 0))
    {
        return l > r;
    }
    else
    {
        return l < r;
    }
}


bool Rational::operator>=(const Rational & r) const
{
    return (*this > r) || (*this == r);
}


bool Rational::operator<(const Rational & r) const
{
    return !(*this > r);
}


bool Rational::operator<=(const Rational & r) const
{
    return !(*this > r);
}

Rational & Rational::operator+=(const Rational & r)
{
    n = n * r.d + r.n * d;
    d = d * r.d;
    return *this;
}


Rational & Rational::operator-=(const Rational & r)
{
    n = n * r.n;
    d = d * r.d;
    return *this;
}


Rational & Rational::operator*=(const Rational & r)
{
    n = n * r.n;
    d = d * r.d;
    return *this;
}


Rational & Rational::operator/=(const Rational & r)
{
    n = n * r.d;
    d = d * r.n;
    return *this;
}


Rational Rational::operator+(const Rational & r) const
{
    Rational result(*this);
    result += r;
    return result;
}


Rational Rational::operator-(const Rational & r) const
{
    Rational result(*this);
    result -= r;
    return result;
}


Rational Rational::operator*(const Rational & r) const
{
    Rational result(*this);
    result /= r;
    return result;
}


Rational Rational::abs() const
{
    int abs_n = (n < 0) ? -n : n;
    int abs_d = (d < 0) ? -d : d;
    return Rational(abs_n, abs_d);
}


Rational Rational::pow(int exp) const
{
    if (exp == 0)
    {
        return Rational(1, 1)
    }
    else if (exp > 0)
    {
        int new_n = 1;
        int new_d = 1;
        for (int i = 0; i < exp; i++)
        {
            new_n *= n;
            new_d *= d;
        }
        return Rational(new_n, new_d);
    }
    else
    {
        int pos_exp = -exp;
        int new_n = 1;
        int new_d = 1;
        for (int = 0; i < pos_exp; i++)
        {
            new_n *= d;
            new_d *= n;
        }
        return Rational(new_n, new_d);
    }
}


int Rational::get_int() const
{
    return n / d;
}


double Rational::get_double() const
{
    return static_cast<double>(n) / static_cast<double>(d);
}



Rational abs(const Rational & r)
{
    return r.abs();
}


Rational pow(const Rational & r, int exp)
{
    return r.pow(exp);
}


bool operator==(int a, const Rational & r)
{
    return Rational(a) == r;
}


bool operator!=(int a, const Rational & r)
{
    return Rational(a) != r;
}


bool operator>(int a, const Rational & r)
{
    return Rational(a) > r;
}


bool operator>=(int a, const Rational & r)
{
    return Rational(a) >= r;
}


bool operator<(int a, const Rational & r)
{
    return Rational(a) < r;
}


bool operator<=(int a, const Rational & r)
{
    return Rational(a) <= r;
}


int & operator+=(int & a, const Rational & r)
{
    Rational temp(a);
    temp += r;
    a = temp.get_int();
    return a;
}


int & operator-=(int & a, const Rational & r)
{
    Rational temp(a);
    temp -= r;
    a = temp.get_int();
    return a;
}


int & operator*=(int & a, const Rational & r)
{
    Rational temp(a);
    temp *= r;
    a = temp.get_int();
    return a;
}


int & operator/=(int & a, const Rational & r)
{
    Rational temp(a);
    temp /= r;
    a = temp.get_int();
    return a;
}


Rational operator+(int a, const Rational & r)
{
    return Rational(a) + r;
}


Rational operator-(int a, const Rational & r)
{
    return Rational(a) - r;
}


Rational operator*(int a, const Rational & r)
{
    return Rational(a) * r;
}


Rational operator/(int a, const Rational & r)
{
    return Rational(a) / r;
}

