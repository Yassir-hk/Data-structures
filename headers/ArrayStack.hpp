#pragma once
#include <cstddef>

template <typename T, size_t N>
class ArrayStack {
private:
  T container[N];
  size_t top_idx;

public:
  ArrayStack();
  size_t size() const;
  bool is_empty() const;
  bool is_full() const;
  void push(const T);
  T& top() const;
  void pop();
  void print() const;
};

#include "../sources/ArrayStack.cpp"