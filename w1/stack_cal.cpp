#include "stack_cal.h"

template <typename T>
Stack<T>::Stack(int size)
{
    capacity = size;
    stack = new T[capacity];
    top_idx = -1;
}

template <typename T>
Stack<T>::~Stack() { delete stack;}

template <typename T>
bool Stack<T>::isFull()
{
    if (top_idx == capacity - 1) return 1;
    else return 0;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if (top_idx == -1) return 1;
    else return 0;
}

template <typename T>
T Stack<T>::pop()
{
    return stack[top_idx--];
}

template <typename T>
T Stack<T>::top()
{
    return stack[top_idx];
}

template <typename T>
void Stack<T>::push(T element)
{
    if (isFull())
        return ;
    stack[++top_idx] = element;
}