#include <iostream>


bool is_palindrome(const char* c)
{
    int length = 0;
    while (c[length] != '\0' ) { ++length; }

    int left = 0;
    int right = length - 1;

    while (left < right)
    {
        char leftchar = c[left];
        char rightchar = c[right];

        if (leftchar != rightchar) { return false; }

        left++;
        right--;
    }

    return true;
}


int main()
{
    char c[42];
    std::cin.getline(c, 42);

    std::cout << is_palindrome(c) << '\n';

    return 0;
}
