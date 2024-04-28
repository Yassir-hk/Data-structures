#pragma once
#include <cstddef>

template <typename T, size_t N>
class ArrayQueue {
private:
  T container[N];
  size_t head_idx;
  size_t tail_idx;

public:
  ArrayQueue();
  void print() const;
  void push(const T&);
  void pop();
  bool is_empty() const;
  bool is_full() const;
  size_t size() const;
  size_t capacity() const;
  T& front() const;
  T& back() const;
};

#include "../sources/ArrayQueue.cpp"