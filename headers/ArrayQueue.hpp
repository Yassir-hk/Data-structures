#pragma once
#include <ostream>
#include <cstddef>

template<typename T, size_t N>
class ArrayQueue {
private:
  T container[N];
  size_t head_idx;
  size_t tail_idx;

public:
  ArrayQueue();
  void push(const T&);
  void pop();
  bool is_empty() const;
  bool is_full() const;
  size_t size() const;
  size_t capacity() const;
  T& front();
  T& back();

  friend std::ostream& operator<<(std::ostream& os, const ArrayQueue<T, N>& queue) {
    if (queue.is_empty()) return os;
    for (size_t i = queue.head_idx; i < queue.tail_idx; ++i) {
      const size_t idx = i % N;
      os << queue.container[idx];
      if (i < queue.tail_idx - 1) os << " ";
    }
    return os;
  }
};

#include "../sources/ArrayQueue.cpp"