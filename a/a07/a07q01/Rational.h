/**************************************************

File : Rational.h
Author : Brysen Landis

 *************************************************/

#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H


int GCD(int, int);
int sign(int);

class Rational
{
public:
    Rational(int a = 0, int b = 1) :  n(a), d(b) {}
    Rational(const Rational & r) : n(r.n), d(r.d) {}
    int get_n() const { return n; }
    int get_d() const { return d; }

    void reduce();

    bool & operator==(const Rational &) const;
    bool & operator==(const Rational &) const;
    bool & operator> (const Rational &) const;
    bool & operator>=(const Rational &) const;
    bool & operator<(const Rational &) const;
    bool & operator<=(const Rational &) const;

    Rational & operator+=(const Rational &);
    Rational & operator-=(const Rational &);
    Rational & operator*=(const Rational &);
    Rational & operator/=(const Rational &);

    Rational operator+() const;
    Rational operator-() const;

    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;

    Rational abs() const;
    Rational pow(int) const;

private:
    int n;
    int d;
};

std::ostream & operator<<(std::ostream &, const Rational &);
std::ostream & operator>>(std::istream &, Rational &);

void reduce(Rational &);
Rational abs(const Rational &);
Rational pow(const Rational &, int);

bool operator==(int, const Rational &);
bool operator!=(int, const Rational &);
bool operator> (int, const Rational &);
bool operator>=(int, const Rational &);
bool operator< (int, const Rational &);
bool operator<=(int, const Rational &);

int & operator+=(int &, const Rational &);
int & operator-=(int &, const Rational &);
int & operator*=(int &, const Rational &);
int & operator/=(int &, const Rational &);

Rational operator+(int, const Rational &);
Rational operator-(int, const Rational &);
Rational operator*(int, const Rational &);
Rational operator/(int, const Rational &);

bool operator==(double, const Rational &);
bool operator!=(double, const Rational &);
bool operator> (double, const Rational &);
bool operator>=(double, const Rational &);
bool operator< (double, const Rational &);
bool operator<=(double, const Rational &);

double & operator+=(double &, const Rational &);
double & operator-=(double &, const Rational &);
double & operator*=(double &, const Rational &);
double & operator/=(double &, const Rational &);

double operator+(double &, const Rational &);
double operator-(double &, const Rational &);
double operator*(double &, const Rational &);
double operator/(double &, const Rational &);


#endif
