#include "LoanBookHeap.h"

template <class T>
LoanBookHeap<T>::LoanBookHeap(int theCapacity)
{
    if (theCapacity < 1) throw "Capacity must be >= 1\n";
    capacity = theCapacity;
    heapSize = 0;
    heap = new T[capacity + 1];
}

template <class T>
LoanBookHeap<T>::~LoanBookHeap()
{
    delete[] heap;
}

template <class T>
void LoanBookHeap<T>::insert(const T &e)
{
    int currentNode;
    T* temp;

    if (heapSize == capacity)
    {
        temp = new T[capacity*2+1];
        std::copy(heap, heap + heapSize, temp);
        delete[] heap;
        heap = temp;
        capacity *= 2;
    }
    currentNode = ++heapSize;
    while (currentNode != 1 && e > heap[currentNode / 2])
    {
        heap[currentNode] = heap[currentNode/2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void LoanBookHeap<T>::pop()
{
    int currentNode, child;

    if (heapSize == 0)
        throw "Heap is empty\n";
    //delete heap[1];
    T &lastE = heap[heapSize--];
    currentNode = 1;
	child = 2;
    while (child <= heapSize) // important!!!!
    {
        if (child < heapSize && heap[child] < heap[child+1]) child++;

        if (heap[child] < lastE) break;
        heap[currentNode] = heap[child];
        currentNode = child;
		child *= 2;
    }
    heap[currentNode] = lastE;
}

template <class T>
void LoanBookHeap<T>::print()
{
	for (int i = 1; i < heapSize+1; i++)
		std::cout << heap[i] << std::endl;
}