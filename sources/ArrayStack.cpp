#include <cassert>
#include <iostream>
#include "../headers/ArrayStack.hpp"

template<typename T, size_t N>
ArrayStack<T, N>::ArrayStack() {
  top_idx = 0;
}

template<typename T, size_t N>
size_t ArrayStack<T, N>::size() const {
  return top_idx;
}

template<typename T, size_t N>
bool ArrayStack<T, N>::is_empty() const {
  return top_idx == 0;
}

template<typename T, size_t N>
bool ArrayStack<T, N>::is_full() const {
  return top_idx == N;
}

template<typename T, size_t N>
void ArrayStack<T, N>::push(const T data) {
  assert(!is_full());
  container[top_idx++] = data;
}

template<typename T, size_t N>
void ArrayStack<T, N>::pop() {
  assert(!is_empty());
  top_idx--;
}

template<typename T, size_t N>
T& ArrayStack<T, N>::top() const {
  assert(!is_empty());
  return container[top_idx];
}

template<typename T, size_t N>
void ArrayStack<T, N>::print() const {
  for (size_t i = 0; i < N; ++i) {
    std::cout << " " << container[i];
  }
}
