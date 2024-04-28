#pragma once
#include <cstddef>

template<typename T>
struct Node {
  T data;
  Node<T> *next;
  Node<T> *prev;
  Node(T value = T(), Node *n = nullptr, Node *p = nullptr):next(n), prev(p), data(value) {}
};

template<typename T>
class DoublyLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  size_t length;
  Node<T>* search_forward(const size_t &) const;
  Node<T>* search_backward(const size_t &) const;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  size_t size() const;
  void push_front(const T &);
  void push_back(const T &);
  void insert(const size_t &, const T &);
  void pop_front();
  void pop_back();
  void remove_at(const size_t &);
  void remove_node(Node<T> *);
  void clear();
  void print() const;
  T& operator[](const size_t &) const;
  T& front() const;
  T& back() const;
};

#include "../sources/DoublyLinkedList.cpp"