#pragma once

#include <iostream>
#include <algorithm>
#include <string>

template <class T>
class LoanBookHeap
{
    private:
        T* heap;
        int heapSize;
        int capacity;
    public:
        LoanBookHeap(int theCapacity = 10);
        ~LoanBookHeap();

        void insert(const T &e);
        void pop();
        void print();
};