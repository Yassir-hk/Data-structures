#pragma once

// Stack based array

template <typename T>
class Stack
{
    T *stackArray;
    long stackSize;
    long stackTop;
public:
    Stack(const long);
    ~Stack();
    long size() const;
    bool is_empty() const;
    bool is_full() const;
    void push(const T&);
    T pop();
    T& top() const;
};
