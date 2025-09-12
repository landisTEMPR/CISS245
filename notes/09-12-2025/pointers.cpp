//----------------------------------------------------------------------------
// NOTES:
//   Reference variables are actually pointers.
//
//   There is a part of your memory that you cannot touch. This is called the
//   heap. We've been using the stack up until this point. The heap is many
//   times larger than the stack.
//   Pointers allow you to access this part of the memory. If you want to make
//   your program faster and use more memory you must use pointers  to access
//   the heap. This is important for data-structures in CISS350. Data-
//   structures allow you to organize large amounts of data and access them
//   quickly and in an organized way. EX. Binary Tree
//----------------------------------------------------------------------------

#include <iostream>

int main()
{
    int x = 42;
    long int y = 0;
    long long int z = 0;
    long long w = 0;
    std::cout << sizeof(x) << '\n';
    std::cout << &(x) << ' ' << x << '\n'; // &(x) is the the address operator
    std::cout << (long long)(&(x)) << '\n';
                           
    return 0;
}
