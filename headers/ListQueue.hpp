#pragma once
#include <stddef.h>
#include "SinglyLinkedList.hpp"

template<typename T>
class ListQueue {
private:
  SinglyLinkedList<T> container;

public:
  size_t size() const;
  bool is_empty() const;
  void push(const T data);
  void pop();
  T& front() const;
  T& back() const;
  void print() const;
};

#include "../sources/ListQueue.cpp"