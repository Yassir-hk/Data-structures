#pragma once

#include <iostream>
#include <stdexcept>


// Stack class represent the stack data structure based on array
template <typename T, size_t N>
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
    void display() const;
};


// Return the current number of element in the stack
template <typename T, size_t N>
size_t Stack<T, N>::size() const
{
  return stackTop;
}

// Check if there is no element in the stack
template <typename T, size_t N>
bool Stack<T, N>::is_empty() const
{
  return stackTop;
}

// Check if the maximum capacity of the stack is used
template <typename T, size_t N>
bool Stack<T, N>::is_full() const
{
  return stackTop == N;
}

// Add element to the top of the stack
template <typename T, size_t N>
void Stack<T, N>::push(const T &data)
{
  if (is_full())
    throw std::runtime_error("Stack is full");

  buffer[stackTop++] = data;
}

// Remove and return the top element of the stack
template <typename T, size_t N>
T &Stack<T, N>::pop()
{
  if (is_empty())
    throw std::runtime_error("Stack is empty");

  return buffer[stackTop--];
}

// Return the top element of the stack
template <typename T, size_t N>
T &Stack<T, N>::top() const
{
  if (is_empty())
    throw std::runtime_error("Stack is empty");

  return buffer[stackTop];
}

// Display the content of the stack
template <typename T, size_t N>
void Stack<T, N>::display() const
{
  for (size_t i = 0; i < N; ++i)
    std::cout << " " << buffer[i];
}