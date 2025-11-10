#include <iostream>
#include "Rational.h"

Rational::Rational(int n, int d)
    : n_(n), d_(d)
{}

Rational::~Rational()
{}

Rational & Rational::operator+=(const Rational & r)
{
    // a/b += c/d
    // left fraction to be (a*d + b*c)/(b*d)
    n_ = n_ * r.d_ + d_ * r.n_;
    d_ *= r.d_;

    // there is a automatic parameter passed into this function
    // parameter name "this"
    return (*this);
}

Rational Rational::operator+(const Rational & r) const
{
    // Rational ret = (*this); // (n_, d_);
    // ret += r;
    // return ret;
    return (Rational(*this) += r);
}

// Rational & Rational::operator+=(int i);
// {
//     return ((*this) += Rational(r, 1));
// }

// Rational Rational::operator+(int i)
// {
//     return (Rational(*this) += Rational(i, 1));
// }



Rational & Rational::operator-=(const Rational & r)
{
    n_ = n_ * r.d_ - d_ * r.n_;
    d_ *= r.d_;
    return (*this);
}

Rational Rational::operator-(const Rational & r) const
{
    return (Rational(*this) -= r);
}

void Rational::set_n(int n)
{
    n_ = n;
}

void Rational::print() const
{
    std::cout << n_ << '/' << d_ << '\n';
}

int Rational::get_n() const
{
    return n_;
}

int Rational::n() const
{
    return n_;
}

int & Rational::n()
{
    return n_;
}

int Rational::d() const
{
    return d_;
}

int & Rational::d()
{
    return d_;
}

int Rational::get_d() const
{
    return d_;
}

std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
    cout << r.get_n() << '/' << r.get_d();
    return cout;
}

std::istream & operator>>(std::istream & cin, Rational & r)
{
    int n, d;
    cin >> n >> d;
    r.n() = n;
    r.d() = d;
    return cin;
}
