#ifndef INTPOINTER_H
#define INTPOINTER_H

class IntPointer // example of smart pointers
{
  public:
    IntPointer(int);
    IntPointer(const IntPointer &);
    ~IntPointer();
    //int dereference() const;
    int operator*() const;
    int & operator*();
    void deallocate();
  private:
    int * p_;
};
#endif
