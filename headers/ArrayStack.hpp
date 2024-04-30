#pragma once
#include <ostream>
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
  void print() const;
  void push(const T);
  void pop();
  T& top();

  friend std::ostream& operator<<(std::ostream& os, const ArrayStack<T, N>& stack) {
    if (queue.is_empty()) return os;
    for (size_t i = 0; i < stack.top_idx; ++i) {
      os << container[i];
      if (i < stack.top_idx - 1) os << " ";
    }
  }
};

#include "../sources/ArrayStack.cpp"