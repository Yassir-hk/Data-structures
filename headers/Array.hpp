#pragma once
#include <cstddef>

template<typename T>
class Array {
private:
  T *container;
  size_t array_size;

public:
  Array(size_t array_size, T value);
  ~Array();
  size_t size() const;
  void resize(size_t array_size, T value);
  void push_back(T value);
  void pop_back();
  void insert_at(size_t index, T value);
  void remove_at(size_t index);
  T& operator[](size_t index);
  T* front() const;
};