#ifndef STACK_CAL_H
# define STACK_CAL_H

template <typename T>
class Stack
{
    private:
        int top_idx, capacity;
        T* stack;
    public:
        Stack(int size);
        ~Stack();

        bool isFull();
        bool isEmpty();
        T pop();
        T top();
        void push(T element);
};
#endif