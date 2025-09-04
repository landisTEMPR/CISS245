#include <iostream>

// Note: This function assumes the array has enough capacity
// Algorithm should be tailored to who and what you are writing it for
void insertElement(int arr[], int& currentSize,
                   int capacity, int element, int position)
{
    if (currentSize >= capacity)
    {
        std::cout << "Array is full. Cannot insert." << std::endl;
        return;
    }
    if (position < 0 || position > currentSize)
    {
        std::cout << "Invalid insertion position." << std::endl;
        return;
    }

    // Shift elements to the right
    for (int i = currentSize - 1; i >= position; --i)
    {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[position] = element;

    // Increment current size
    currentSize++;
}

int main()
{
    const int MAX_CAPACITY = 10;
    int myArray[MAX_CAPACITY] = {10, 20, 30, 40, 50};
    int currentElements = 5;

    std::cout << "Original Array: ";
    for (int i = 0; i < currentElements; ++i)
    {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    insertElement(myArray, currentElements, MAX_CAPACITY, 25, 2);// Insert 25 at index 2

    std::cout << "Array after insertion: ";
    for (int i = 0; i < currentElements; ++i)
    {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
