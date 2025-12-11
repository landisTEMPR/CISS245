// File : Deque.h
// Author : Brysen Landis
#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>

class UnderflowError {}; 
class OverflowError {};

template <typename T>
class Deque
{
public:
    Deque(int cap = 5)
        : x_(nullptr), size_(0), cap_(cap)
    {
        x_ = new T[cap_];
    }
    
    Deque(const Deque<T>& other)
        : x_(nullptr), size_(other.size_), cap_(other.cap_)
    {
        x_ = new T[cap_];
        for (int i = 0; i < size_; ++i)
        {
            x_[i] = other.x_[i];
        }
    }
    
    ~Deque()
    {
        delete[] x_;
    }
    
    Deque<T>& operator=(const Deque<T>& other)
    {
        if (this == &other)
        {
            return *this;
        }
        
        delete[] x_;
        size_ = other.size_;
        cap_ = other.cap_;
        x_ = new T[cap_];
        
        for (int i = 0; i < size_; ++i)
        {
            x_[i] = other.x_[i];
        }
        
        return *this;
    }
    
    void insert_head(const T& val)
    {
        if (size_ == cap_)
        {
            expand();
        }
        
        for (int i = size_; i > 0; --i)
        {
            x_[i] = x_[i - 1];
        }
        
        x_[0] = val;
        ++size_;
    }
    
    void insert_tail(const T& val)
    {
        if (size_ == cap_)
        {
            expand();
        }
        
        x_[size_] = val;
        ++size_;
    }
    
    T remove_head()
    {
        if (size_ == 0)
        {
            throw UnderflowError();
        }
        
        T head = x_[0];
        
        for (int i = 0; i < size_ - 1; ++i)
        {
            x_[i] = x_[i + 1];
        }
        
        --size_;
        return head;
    }
    
    T remove_tail()
    {
        if (size_ == 0)
        {
            throw UnderflowError();
        }
        
        T tail = x_[size_ - 1];
        --size_;
        return tail;
    }
    
    void clear()
    {
        size_ = 0;
    }
    
    bool is_empty() const
    {
        return size_ == 0;
    }
    
    int size() const
    {
        return size_;
    }
    
    int capacity() const
    {
        return cap_;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Deque<T>& dq)
    {
        out << "[";
        for (int i = 0; i < dq.size_; ++i)
        {
            out << dq.x_[i];
            if (i < dq.size_ - 1)
            {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

private:
    T* x_;
    int size_;
    int cap_;
    
    void expand()
    {
        int new_cap = cap_ * 2;
        T* new_x = new T[new_cap];
        
        for (int i = 0; i < size_; ++i)
        {
            new_x[i] = x_[i];
        }
        
        delete[] x_;
        x_ = new_x;
        cap_ = new_cap;
    }
};

#endif
