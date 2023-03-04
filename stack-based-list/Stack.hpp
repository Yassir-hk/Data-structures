#pragma once

/*
 * Linked list implementation of stack
 */

template <class T> struct Node
{
    T data;
    Node<T> *next;
    Node<T>(const T& d, Node<T> *n):data(d), next(n) {}
};

template <class T>
class Stack
{
    Node<T> *stackTop;
    size_t stackSize;
public:
    Stack() : stackTop(nullptr), stackSize(0) {};
    ~Stack();
    size_t size() const;
    bool is_empty() const;
    void display() const;
    void clear();
    void push(const T&);
    T& top() const;
    T pop();
};
