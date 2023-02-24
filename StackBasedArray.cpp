#include <iostream>
#include <stdexcept>
#include "StackBasedArray.hpp"

using namespace std;

template <typename T>
Stack<T>::Stack(const long stackSize)
{
    this->stackTop = -1;
    this->stackSize = stackSize;
    this->stackArray = new T[stackSize];
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] (this->stackArray);
}

// Method return the number of element inserted in the stack

template <typename T>
long Stack<T>::size() const
{
    return stackTop == -1 ? 0 : stackTop + 1;
}

// Method check if there is no element in the stack

template <typename T>
bool Stack<T>::is_empty() const
{
    return stackTop == -1;
}

// Method check if the maximum capacity of the stack is used

template <typename T>
bool Stack<T>::is_full() const
{
    return stackTop == stackSize - 1;
}

// Method adds one element to the top of the stack

template <typename T>
void Stack<T>::push(const T& data)
{
    if (is_full()) { throw overflow_error("Stack is full"); }
    stackArray[++stackTop] = data;
}

// Method removes and returns the top element of the stack

template <typename T>
T Stack<T>::pop()
{
    if (is_empty()) { throw underflow_error("Stack is empty"); }
    return stackArray[stackTop--];
}

// Method return the top element of the stack without removing it

template <typename T>
T& Stack<T>::top() const
{
    if (is_empty()) { throw underflow_error("Stack is empty"); }
    return stackArray[stackTop];
}
