#pragma once


/*
 * Array implementation of stack
 */

template <class T, size_t N>
class Stack
{
private:
    T buffer[N];
    size_t stackTop;
public:
    Stack() : stackTop(0) {};
    size_t size() const;
    bool is_empty() const;
    bool is_full() const;
    void push(const T&);
    T& top() const;
    T& pop();
    void display_stack() const;
};