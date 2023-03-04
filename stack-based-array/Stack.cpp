#include <iostream>
#include <stdexcept>
#include "Stack.hpp"
using namespace std;

// Return the current number of element in the stack
template <class T, size_t N>
size_t Stack<T, N>::size() const {
    return stackTop;
}

// Check if there is no element in the stack
template <class T, size_t N>
bool Stack<T, N>::is_empty() const {
    return stackTop;
}

// Check if the maximum capacity of the stack is used
template <class T, size_t N>
bool Stack<T, N>::is_full() const {
    return stackTop == N;
}

// Add element to the top of the stack
template <class T, size_t N>
void Stack<T, N>::push(const T& data)
{
    if (is_full()) {
        throw runtime_error("Stack is full");
    }

    buffer[stackTop++] = data;
}

// Remove and return the top element of the stack
template <class T, size_t N>
T& Stack<T, N>::pop()
{
    if (is_empty()) {
        throw runtime_error("Stack is empty");
    }

    return buffer[stackTop--];
}

// Return the top element of the stack
template <class T, size_t N>
T& Stack<T, N>::top() const
{
    if (is_empty()) {
        throw runtime_error("Stack is empty");
    }

    return buffer[stackTop];
}

// Display the content of the stack
template <class T, size_t N>
void Stack<T, N>::display_stack() const
{
    for (size_t i = 0; i < N; ++i) {
        cout << " " << buffer[i];
    }
}