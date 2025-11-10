#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
  public:
    Rational(int=0, int=1);
    ~Rational();
    void print() const;
    int get_n() const;
    void set_n(int);
    int n() const; // reads and returns n_
    int & n();     // returns a reference to n_
    int get_d() const;
    // write a set_d
    int d() const;
    int & d();
    
    Rational & operator+=(const Rational &);
    Rational operator+(const Rational & r) const;

    //Rational operator+(int);
    //Rational & operator+=(int);

    Rational & operator-=(const Rational &);
    Rational operator-(const Rational & r) const;

private:
    int n_, d_;
};


std::ostream & operator<<(std::ostream &, const Rational &);
std::istream & operator>>(std::istream & cin, Rational & r);
    
#endif
