#pragma once

/*
 * Doubly linked list implementation
 */

template <typename T>
struct Node
{
  T data;
  Node<T> *next;
  Node<T> *prev;
  Node(T value, Node *n = nullptr, Node *p = nullptr) : next(n), prev(p), data(value) {}
};

template <typename T>
class DoublyLinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  size_t listSize;
  Node<T> *search_forward(const size_t &) const;
  Node<T> *search_backward(const size_t &) const;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0){};
  ~DoublyLinkedList();
  size_t size() const;
  T pop_back();
  T pop_front();
  T remove_at(const size_t &);
  void clear();
  void display() const;
  void push_back(const T &);
  void push_front(const T &);
  void insert(const size_t &, const T &);
  T &operator[](const size_t &) const;
};
