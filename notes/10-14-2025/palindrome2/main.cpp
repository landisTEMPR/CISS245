#include <iostream>
bool ispalindrome(const char s[])
{
    int len = 0;
    while (s[len] != '\0')
    {
        ++len;
    }

    char l = 0;
    char r = len - 1;
    
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        ++l;
        --r;
    }
    return true;
}

int main()
{
    char s[1024];
    std::cin.getline(s, 1024);
    
    std::cout << ispalindrome(s) << '\n';
    
    return 0;
}
