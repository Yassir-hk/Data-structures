#include <cassert>
#include <iostream>
#include "../headers/ArrayQueue.hpp"

template<typename T, size_t N>
ArrayQueue<T, N>::ArrayQueue() {
  head_idx = 0;
  tail_idx = 0;
}

template<typename T, size_t N>
bool ArrayQueue<T, N>::is_empty() const {
  return size() == 0;
}

template<typename T, size_t N>
bool ArrayQueue<T, N>::is_full() const {
  return size() == capacity();
}

template<typename T, size_t N>
size_t ArrayQueue<T, N>::size() const {
  return tail_idx - head_idx;
}

template<typename T, size_t N>
size_t ArrayQueue<T, N>::capacity() const {
  return N;
}

template<typename T, size_t N>
void ArrayQueue<T, N>::push(const T &data) {
  assert(!is_full());
  const size_t idx = tail_idx % N;
  container[idx] = data;
  tail_idx++;
}

template<typename T, size_t N>
void ArrayQueue<T, N>::pop() {
  assert(!is_empty());
  const size_t idx = head_idx % N;
  head_idx++;
}

template<typename T, size_t N>
T& ArrayQueue<T, N>::front() {
  assert(!is_empty());
  return container[tail_idx % N];
}

template<typename T, size_t N>
T& ArrayQueue<T, N>::back() {
  assert(!is_empty());
  return container[head_idx % N];
}