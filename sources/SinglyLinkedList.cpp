#include <cassert>
#include <iostream>
#include "../headers/SinglyLinkedList.hpp"

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
  list_size = 0;
  head = nullptr;
  tail = nullptr;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
  clear();
}

template<typename T>
T& SinglyLinkedList<T>::front() const {
  assert(list_size > 0);
  return head->data;
}

template<typename T>
T& SinglyLinkedList<T>::back() const {
  assert(list_size > 0);
  return tail->data;
}

template<typename T>
void SinglyLinkedList<T>::push_front(T data) {
  Node<T> *new_node = new Node<T>(data);
  new_node->next = head;
  head = new_node;
  if (list_size == 0) tail = new_node;
  list_size++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(T data) {
  if (list_size == 0) return push_front(data);
  Node<T> *new_node = new Node<T>(data);
  tail->next = new_node;
  tail = new_node;
  list_size++;
}

template<typename T>
void SinglyLinkedList<T>::insert_at(size_t position, T data) {
  assert(position >= 0 && position <= list_size);
  if (position == 0) return push_front(data);
  if (position == list_size) return push_back(data);

  Node<T> *it = head;
  for (size_t idx = 0; idx < position - 1; ++idx) { 
    it = it->next;
  }

  Node<T> *new_node = new Node<T>(data);
  new_node->next = it->next;
  it->next = new_node;
  list_size++;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
  if (list_size == 0) return;
  Node<T> *temp = head;
  head = head->next;
  delete temp;
  list_size--;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
  if (list_size == 0) return;
  if (list_size == 1) return pop_front();
  
  Node<T> *it = head;
  while (it->next != tail) {
    it = it->next;
  }

  delete tail;
  it->next = nullptr;
  tail = it;
  list_size--;
}

template<typename T>
void SinglyLinkedList<T>::remove_at(size_t position) {
  assert(position >= 0 && position < list_size);
  if (position == 0) return pop_front();
  if (position == list_size - 1) return pop_back();

  Node<T> *it = head;
  for (size_t idx = 0; idx < position - 1; ++idx) {
    it = it->next;
  }

  Node<T> *temp = it->next;
  it->next = temp->next;
  delete temp;
  list_size--;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
  while (list_size) {
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
  return list_size;
}
