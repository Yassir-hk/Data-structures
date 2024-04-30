#pragma once
#include <stddef.h>

template<typename T>
struct Node {
  T data;
  Node<T> *next;
  Node<T> *prev;
  Node(T value = T(), Node *n = nullptr, Node *p = nullptr):next(n), prev(p), data(value) {}
};

template<typename T>
class CircularLinkedList {
private:
  Node<T> sentinel;
  size_t length;

public:
  CircularLinkedList();
  ~CircularLinkedList();
  T& back() const;
  T& front() const;
  void print() const;
  void push_back(const T &);
  void push_front(const T &);
  void insert_at(const T &, const size_t);
  void remove_at(const size_t);
  void pop_front();
  void pop_back();
  void clear();
  size_t size() const;
  Node<T>* find(const T &) const;
  Node<T>* search_forward(const size_t) const;
  Node<T>* search_backward(const size_t) const;
};

#include "../sources/CircularLinkedList.cpp"