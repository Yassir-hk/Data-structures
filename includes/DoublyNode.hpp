#pragma once


template <typename T>
struct Node
{
  T data;
  Node<T> *next;
  Node<T> *prev;
  Node(T value = T(), Node *n = nullptr, Node *p = nullptr) : next(n), prev(p), data(value) {}
};
