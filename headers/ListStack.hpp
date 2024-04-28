#pragma once
#include "SinglyLinkedList.hpp"

template<typename T>
class ListStack {
private:
  SinglyLinkedList<T> container;

public:
  size_t size() const;
  bool is_empty() const;
  void push(const T data);
  void pop();
  T& top();
  void print() const;
};

#include "../sources/ListStack.cpp"