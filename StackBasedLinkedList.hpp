#pragma once

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T>(const T& d, Node<T> *n):data(d), next(n) {}
}

template <typename T>
class Stack
{
    Node<T> *stackTop;
    size_t stackSize;
public:
    Stack();
    ~Stack();
    size_t size() const;
    bool is_empty() const;
    void display() const;
    void clear() const;
    void push(const T&);
    T& top() const;
    T pop();
};
