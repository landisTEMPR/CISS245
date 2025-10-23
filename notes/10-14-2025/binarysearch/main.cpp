#include <iostream>


int main()
{
    int a[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(a) / sizeof(a[0]);

    int * found;

    found = binarysearch(&a[0], &a[0] + n, 7);
    if (found != NULL)
        std::cout << "Found 7 at index " << (found - &a[0]) << " (value: " << *found << ")\n";
    else
        std::cout << "7 not found\n";

    found = binarysearch(&a[0], &a[0] + n, 2);
    if (found != NULL)
        std::cout << "Found 2 at index " << (found - &a[0]) << " (value: " << *found << ")\n";
    else
        std::cout << "2 not found\n";

    // Edge cases
    found = binarysearch(&a[0], &a[0], 1); // empty range
    if (found == NULL) std::cout << "Empty range -> not found\n";

    return 0;
}
