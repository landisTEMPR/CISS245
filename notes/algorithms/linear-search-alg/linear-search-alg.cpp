#include <iostream>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // return index if found
        }
    }
    return -1; // not found
}

int main()
{
    int arr[] = {10, 25, 30, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = linearSearch(arr, n, key);

    if (result != -1)
    {
        std::cout << "Element found at index " << result << "\n";
    }
    else
    {
        std::cout << "Element not found\n";
    }

    return 0;
}
