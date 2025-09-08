#include <iostream>

int count_occurrences(int arr[], int n, int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {10, 25, 30, 25, 50, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 25;

    int result = count_occurrences(arr, n, key);

    std::cout << "Element " << key << " occurs " << result << " times\n";

    return 0;
}
