#include <cassert>
#include <iostream>
#include "../headers/SinglyLinkedList.hpp"

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
  length = 0;
  head = nullptr;
  tail = nullptr;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
  clear();
}

template<typename T>
T& SinglyLinkedList<T>::front() const {
  assert(length > 0);
  return head->data;
}

template<typename T>
T& SinglyLinkedList<T>::back() const {
  assert(length > 0);
  return tail->data;
}

template<typename T>
void SinglyLinkedList<T>::push_front(T data) {
  Node<T> *new_node = new Node<T>(data);
  new_node->next = head;
  head = new_node;
  if (length == 0) tail = new_node;
  length++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(T data) {
  if (length == 0) return push_front(data);
  Node<T> *new_node = new Node<T>(data);
  tail->next = new_node;
  tail = new_node;
  length++;
}

template<typename T>
void SinglyLinkedList<T>::insert_at(size_t position, T data) {
  assert(position >= 0 && position <= length);
  if (position == 0) return push_front(data);
  if (position == length) return push_back(data);

  Node<T> *it = head;
  for (size_t idx = 0; idx < position - 1; ++idx) { 
    it = it->next;
  }

  Node<T> *new_node = new Node<T>(data);
  new_node->next = it->next;
  it->next = new_node;
  length++;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
  if (length == 0) return;
  Node<T> *temp = head;
  head = head->next;
  delete temp;
  length--;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
  if (length == 0) return;
  if (length == 1) return pop_front();
  
  Node<T> *it = head;
  while (it->next != tail) {
    it = it->next;
  }

  delete tail;
  it->next = nullptr;
  tail = it;
  length--;
}

template<typename T>
void SinglyLinkedList<T>::remove_at(size_t position) {
  assert(position >= 0 && position < length);
  if (position == 0) return pop_front();
  if (position == length - 1) return pop_back();

  Node<T> *it = head;
  for (size_t idx = 0; idx < position - 1; ++idx) {
    it = it->next;
  }

  Node<T> *temp = it->next;
  it->next = temp->next;
  delete temp;
  length--;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
  while (length) {
    pop_front();
  }
}

template<typename T>
void SinglyLinkedList<T>::print() const {
  Node<T> *it = head;
  while (it) {
    std::cout << it->data << " ";
    it = it->next;
  }
  std::cout << std::endl;
}

template<typename T>
size_t SinglyLinkedList<T>::size() const {
  return length;
}
