#ifndef W1_STACK_CAL_H
# define W1_STACK_CAL_H
# include <iostream>
using namespace std;

template <typename T>
class Stack
{
    private:
        int top_idx, capacity;
        T* stack;
    public:
        Stack(int size)
        {
            capacity = size;
            stack = new T[capacity];
            top_idx = -1;
        };
        ~Stack() { delete stack;};
        bool isFull()
        {
            if (top_idx == capacity - 1) return 1;
            else return 0;
        };

        bool isEmpty()
        {
            if (top_idx == -1) return 1;
            else return 0;
        };

        T pop()
        {
            return stack[top_idx--];
        };

        T top()
        {
            return stack[top_idx];
        };

        void push(T element)
        {
            if (isFull())
                return ;
            stack[++top_idx] = element;
        };
};
#endif