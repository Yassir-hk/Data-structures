#include <cassert>
#include <iostream>
#include "../headers/CircularLinkedList.hpp"

template<typename T>
CircularLinkedList<T>::CircularLinkedList() {
  sentinel.next = &sentinel;
  sentinel.prev = &sentinel;
  list_size = 0;
}

template<typename T>
CircularLinkedList<T>::~CircularLinkedList() {
  clear();
}

template<typename T>
size_t CircularLinkedList<T>::size() const {
  return list_size;
}

template<typename T>
void CircularLinkedList<T>::print() const {
  for (auto it = sentinel.next; it != &sentinel; it = it->next) {
    std::cout << " " << it->data;
  }
}

template<typename T>
void CircularLinkedList<T>::push_front(const T &data) {
  sentinel.next = new Node<T>(data, sentinel.next, &sentinel);
  list_size++;
  if (list_size == 1) {
    sentinel.prev = sentinel.next;
  }
}

template<typename T>
void CircularLinkedList<T>::push_back(const T &data) {
  if (list_size == 0) return push_front(data);
  Node<T> *new_node = new Node<T>(data, &sentinel, sentinel.prev);
  sentinel.prev->next = new_node;
  sentinel.prev = new_node;
  list_size++;
}

template<typename T>
void CircularLinkedList<T>::pop_front() {
  assert(list_size > 0);
  Node<T> *temp = sentinel.next;
  sentinel.next = sentinel.next->next;
  sentinel.next->prev = &sentinel;
  list_size--;
  delete temp;
}

template<typename T>
void CircularLinkedList<T>::pop_back() {
  if (list_size < 2) return pop_front();
  Node<T> *temp = sentinel.prev;
  sentinel.prev = sentinel.prev->prev;
  sentinel.prev->next = &sentinel;
  delete temp;
  list_size--;
}

template<typename T>
void CircularLinkedList<T>::clear() {
  while (list_size) {
    pop_front();
  }
}

template<typename T>
Node<T>* CircularLinkedList<T>::find(const T &data) const {
  for (auto it = sentinel.next; it != &sentinel; it = it->next) {
    if (data == it->data) return it;
  }
  return nullptr;
}

template<typename T>
Node<T>* CircularLinkedList<T>::search_forward(const size_t position) const {
  if (position >= list_size) return nullptr;
  Node<T> *it = sentinel.next;
  for (size_t i = 0; i < position; ++i) {
    it = it->next;
  }
  return it;
}

template<typename T>
Node<T>* CircularLinkedList<T>::search_backward(const size_t position) const {
  if (position >= list_size) return nullptr;
  Node<T> *it = sentinel.prev;
  for (size_t i = list_size - 1; i > position; --i) {
    it = it->prev;
  }
  return it;
}

template<typename T>
T& CircularLinkedList<T>::front() const {
  assert(list_size > 0);
  return sentinel.next->data;
}

template<typename T>
T& CircularLinkedList<T>::back() const {
  assert(list_size > 0);
  return sentinel.prev->data;
}

template<typename T>
void CircularLinkedList<T>::insert_at(const T &data, const size_t position) {
  position %= list_size;
  if (position == 0) return push_front(data);
  Node<T> *target_node = position < list_size / 2 ? search_forward(position) : search_backward(position);
  Node<T> *new_node = new Node<T>(data, target_node, target_node->prev);
  target_node->prev->next = new_node;
  target_node->prev = new_node;
  list_size++;
}

template<typename T>
void CircularLinkedList<T>::remove_at(const size_t position) {
  position %= list_size;
  if (position == 0) return pop_front();
  if (position == list_size - 1) return pop_back();
  Node<T> *target_node = position < list_size / 2 ? search_forward(position) : search_backward(position);
  target_node->prev->next = target_node->next;
  target_node->next->prev = target_node->prev;
  delete target_node;
  list_size--;
}