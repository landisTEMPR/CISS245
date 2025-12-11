#include <iostream>

int main()
{
    IntDynArray a(5); // a models array size 0 within an array of capacity 5
    IntDynArray b(1000); // b.capacity_ is 1000, b.size_ = 0
    a.resize(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 10;
    std::cout << a << '\n'; // prints from (1, 2, 10)
    a = b; // everything b transfered to a
    a.push_back(8); // add 8 to "back" of array, expand automatically if nec.

    // a has a.p_ pointer to an array on the heap
    // a has a.size_
    // a has a.capacity_
    
    
    return 0;
}
