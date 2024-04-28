#pragma once
#include <cstddef>

template<typename T>
struct Node {
  T data;
  Node<T> *next;
  Node(T data): data(data), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  size_t length;

public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  T& front() const;
  T& back() const;
  void push_front(T data);
  void push_back(T data);
  void insert_at(size_t position, T data);
  void pop_front();
  void pop_back();
  void remove_at(size_t position);
  void clear();
  void print() const;
  size_t size() const;
};

#include "../sources/SinglyLinkedList.cpp"