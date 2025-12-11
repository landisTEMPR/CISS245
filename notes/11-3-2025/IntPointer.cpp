#include <iostream>
#include "IntPointer.h"

IntPointer::IntPointer(int i)
    : p_(new int)
{
    *p_ = i;
}

IntPointer::~IntPointer()
{
    std::cout << "IntPointer::~IntPointer() ... " << *p_ << " ... deallocating\n";
    delete p_;
}

// int IntPointer::dereference() const
// {
//     return *p_;
// }

int IntPointer::operator*() const
{
    return *p_;
}

int & IntPointer::operator*()
{
    return *p_;
}

void IntPointer::deallocate()
{
    delete p_;
}

// Default copy cotr (this is wrong) double free error
// IntPointer::IntPointer(const IntPointer & i)
//     : p_(i.p_)
// {}

IntPointer(const IntPointer & i)
    : p_(new int)
{
    *p  = *(i.p_);
}
