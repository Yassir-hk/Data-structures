#include <iostream>
#include <stdexcept>
#include "Stack.hpp"
using namespace std;

// Destructor
template <class T>
Stack<T>::~Stack() {
    clear();
}

// Add element to the top of the stack
template <class T>
void Stack<T>::push(const T& data)
{
    stackTop = new Node<T>(data, stackTop);
    stackSize++;
}

// Remove and return the top element of the stack
template <class T>
T Stack<T>::pop()
{
    if (is_empty()) {
        throw runtime_error("Stack is empty");
    }

    Node<T> *tmp = stackTop;
    const T data = tmp->data;
    stackTop = stackTop->next;
    stackSize--;
    delete temp;
    return data;
}

// Remove all stack elements
template <class T>
void Stack<T>::clear()
{
    while (stackTop)
    {
        auto tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
    }

    stackSize = 0;
}

// Check if there is no element in the stack
template <class T>
bool Stack<T>::is_empty() const {
    return topStack == nullptr;
}

// Return the top element of the stack
template <class T>
T& Stack<T>::top() const
{
    if (is_empty()) {
        throw runtime_error("Stack is empty");
    }

    return stackTop->data;
}

// Return the current number of element in the stack
template <class T>
size_t Stack<T>::size() const {
    return stackSize;
}

// Print all elements of the stack
template <class T>
void Stack<T>::display() const
{
    cout << "{";
    
    for (auto it = stackTop; it; it = it->next) {
        cout << " " << it->data;
    }

    cout << " }";
}