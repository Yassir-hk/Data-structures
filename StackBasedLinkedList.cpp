#include <iostream>
#include "StackBasedLinkedList.hpp"

using namespace std;

template <typename T>
Stack<T>::Stack()
{
    stackTop = nullptr;
    stackSize = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}

// Method adds one element to the top of the stack

template <typename T>
void Stack<T>::push(const T& data)
{
    stackTop = new Node<T>(data, stackTop);
    stackSize++;
}

// Method removes and returns the top element of the stack

template <typename T>
T Stack<T>::pop()
{
    if (is_empty()) { throw underflow_error("Stack is empty"); }

    Node<T> *tmp = stackTop;
    T data = tmp->data;

    stackTop = stackTop->next;
    stackSize--;
    delete temp;

    return data;
}

// Method remove all stack elements

template <typename T>
void Stack<T>::clear()
{
    while (stackTop)
    {
        Node<T> *tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
    }

    stackSize = 0;
}

// Method check if there is no element in the stack

template <typename T>
Stack<T>::is_empty() const
{
    return topStack == nullptr;
}

// Method return the top element of the stack without removing it

template <typename T>
T& Stack<T>::top() const
{
    if (is_empty()) { throw underflow_error("Stack is empty"); }
    return stackTop->data;
}

// Method return the number of element inserted in the stack

template <typename T>
size_t Stack<T>::size() const
{
    return stackSize;
}

// Method print elements of the stack

template <typename T>
void Stack<T>::display() const
{
    cout << "{";
    
    for (Node<T> *it = stackTop; it; it = it->next)
    {
        cout << " " << it->data;
    }

    cout << " }";
}
