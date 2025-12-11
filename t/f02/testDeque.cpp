// File : testDeque.cpp
// Author : Brysen Landis

#include <iostream>
#include "Deque.h"

void print_menu()
{
    std::cout << "=== Deque Tester - Brysen Landis ===" << std::endl;
    std::cout << "1. insert at head" << std::endl;
    std::cout << "2. insert at tail" << std::endl;
    std::cout << "3. remove from head" << std::endl;
    std::cout << "4. remove from tail" << std::endl;
    std::cout << "5. display deque" << std::endl;
    std::cout << "6. check if empty" << std::endl;
    std::cout << "7. get size" << std::endl;
    std::cout << "8. get capacity" << std::endl;
    std::cout << "9. clear deque" << std::endl;
    std::cout << "10. test copy constructor" << std::endl;
    std::cout << "11. test assignment operator" << std::endl;
    std::cout << "0. exit" << std::endl;
    std::cout << "choice: ";
}

void test_insert_head(Deque<int>& dq)
{
    int value;
    std::cout << "\nenter value to insert at head: ";
    std::cin >> value;
    dq.insert_head(value);
    std::cout << "inserted " << value << " at head" << std::endl;
    std::cout << "deque: " << dq << std::endl;
}

void test_insert_tail(Deque<int>& dq)
{
    int value;
    std::cout << "\nenter value to insert at tail: ";
    std::cin >> value;
    dq.insert_tail(value);
    std::cout << "inserted " << value << " at tail" << std::endl;
    std::cout << "deque: " << dq << std::endl;
}

void test_remove_head(Deque<int>& dq)
{
    try
    {
        int value = dq.remove_head();
        std::cout << "\nremoved " << value << " from head" << std::endl;
        std::cout << "deque: " << dq << std::endl;
    }
    catch (const UnderflowError& e)
    {
        std::cout << "\nerror: deque is empty!" << std::endl;
    }
}

void test_remove_tail(Deque<int>& dq)
{
    try
    {
        int value = dq.remove_tail();
        std::cout << "\nremoved " << value << " from tail" << std::endl;
        std::cout << "deque: " << dq << std::endl;
    }
    catch (const UnderflowError& e)
    {
        std::cout << "\nerror: deque is empty!" << std::endl;
    }
}

void test_display(Deque<int>& dq)
{
    std::cout << "\ndeque: " << dq << std::endl;
}

void test_empty(Deque<int>& dq)
{
    if (dq.is_empty())
    {
        std::cout << "\ndeque is empty" << std::endl;
    }
    else
    {
        std::cout << "deque is not empty" << std::endl;
    }
}

void test_size(Deque<int>& dq)
{
    std::cout << "\nsize: " << dq.size() << std::endl;
}

void test_cap(Deque<int>& dq)
{
    std::cout << "\ncapacity: " << dq.capacity() << std::endl;
}

void test_clear(Deque<int>& dq)
{
    dq.clear();
    std::cout << "\ndeque cleared" << std::endl;
    std::cout << "deque: " << dq << std::endl;
}

void test_copy_ctor(Deque<int>& dq)
{
    Deque<int> dq_copy(dq);
    std::cout << "\ncreated copy: " << dq_copy << std::endl;
    std::cout << "original: " << dq << std::endl;
}

void test_assignment_op(Deque<int>& dq)
{
    Deque<int> dq_assign;
    dq_assign = dq;
    std::cout << "\nassigned copy: " << dq_assign << std::endl;
    std::cout << "original: " << dq << std::endl;
}

int main()
{
    Deque<int> dq;
    int choice = -1;
    
    while (choice != 0)
    {
        print_menu();
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
                test_insert_head(dq);
                break;
            case 2:
                test_insert_tail(dq);
                break;
            case 3:
                test_remove_head(dq);
                break;
            case 4:
                test_remove_tail(dq);
                break;
            case 5:
                test_display(dq);
                break;
            case 6:
                test_empty(dq);
                break;
            case 7:
                test_size(dq);
                break;
            case 8:
                test_cap(dq);
                break;
            case 9:
                test_clear(dq);
                break;
            case 10:
                test_copy_ctor(dq);
                break;
            case 11:
                test_assignment_op(dq);
                break;
            case 0:
                std::cout << "exiting..." << std::endl;
                break;
            default:
                std::cout << "invalid choice. try again." << std::endl;
                break;
        }
    }
    
    return 0;
}
