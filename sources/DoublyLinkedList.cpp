#include <cassert>
#include "../headers/DoublyLinkedList.hpp"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  clear();
}

template <typename T>
size_t DoublyLinkedList<T>::size() const {
  return length;
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T &data) {
  Node<T> *new_node = new Node<T>(data, head);
  length == 0 ? tail = new_node : head->prev = new_node;
  head = new_node;
  length++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T &data) {
  Node<T> *new_node = new Node<T>(data, nullptr, tail);
  length == 0 ? head = new_node : tail->next = new_node;
  tail = new_node;
  length++;
}

template <typename T>
void DoublyLinkedList<T>::insert(const size_t &position, const T &data) {
  assert(position >= 0 && position <= length);
  if (position == 0) return push_front(data);
  if (position == length) return push_back(data);

  Node<T> *positionNode = position < length / 2 ? search_forward(position) : search_backward(position);
  Node<T> *new_node = new Node<T>(data, positionNode, positionNode->prev);
  positionNode->prev->next = new_node;
  positionNode->prev = new_node;
  length++;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::search_forward(const size_t &position) const {
  if (position >= length) return nullptr;

  Node<T> *it = head;
  for (size_t i = 0; i < position; ++i) {
    it = it->next;
  }
  return it;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::search_backward(const size_t &position) const {
  if (position >= length) return nullptr;

  Node<T> *it = tail;
  for (size_t i = length - 1; i > position; --i) {
    it = it->prev;
  }
  return it;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
  for (auto it = head; it; it = it->next) {
    std::cout << " " << it->data;
  }
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
  assert(length > 0);
  Node<T> *temp = head;
  head = head->next;
  length--;
  delete temp;
  if (head != nullptr) head->prev = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
  assert(length > 0);
  Node<T> *temp = tail;
  tail = tail->prev;
  delete temp;
  length--;
  if (tail != nullptr) tail->next = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::remove_at(const size_t& position) {
  assert(position >= 0 && position < length);
  if (position == length - 1) return pop_back();
  if (position == 0) return pop_front();

  Node<T> *target_node = (position < length / 2) ? search_forward(position) : search_backward(position);
  const T data = target_node->data;
  target_node->prev->next = target_node->next;
  target_node->next->prev = target_node->prev;
  length--;
  delete target_node;
}

template <typename T>
void DoublyLinkedList<T>::remove_node(Node<T> *target_node) {
  assert(target_node != nullptr && length > 0);
  if (target_node == head) return pop_front();
  if (target_node == tail) return pop_back();

  target_node->next->prev = target_node->prev;
  target_node->prev->next = target_node->next;
  delete target_node;
  length--;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
  while (head != nullptr) {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }

  tail = nullptr;
  length = 0;
}

template <typename T>
T& DoublyLinkedList<T>::operator[](const size_t &position) const {
  assert(position >= 0 && position < length);
  Node<T> *positionNode = position < length / 2 ? search_forward(position):search_backward(position);
  return positionNode->data;
}

template <typename T>
T& DoublyLinkedList<T>::front() const {
  assert(length > 0);
  return head;
}

template <typename T>
T& DoublyLinkedList<T>::back() const {
  assert(length > 0);
  return tail;
}