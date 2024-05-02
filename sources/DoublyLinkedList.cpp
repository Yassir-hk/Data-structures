#include <cassert>
#include "../headers/DoublyLinkedList.hpp"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
  list_size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  clear();
}

template <typename T>
size_t DoublyLinkedList<T>::size() const {
  return list_size;
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T &data) {
  Node<T> *new_node = new Node<T>(data, head);
  list_size == 0 ? tail = new_node : head->prev = new_node;
  head = new_node;
  list_size++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T &data) {
  Node<T> *new_node = new Node<T>(data, nullptr, tail);
  list_size == 0 ? head = new_node : tail->next = new_node;
  tail = new_node;
  list_size++;
}

template <typename T>
void DoublyLinkedList<T>::insert(const size_t &position, const T &data) {
  assert(position >= 0 && position <= list_size);
  if (position == 0) return push_front(data);
  if (position == list_size) return push_back(data);

  Node<T> *positionNode = position < list_size / 2 ? search_forward(position) : search_backward(position);
  Node<T> *new_node = new Node<T>(data, positionNode, positionNode->prev);
  positionNode->prev->next = new_node;
  positionNode->prev = new_node;
  list_size++;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::search_forward(const size_t &position) const {
  if (position >= list_size) return nullptr;

  Node<T> *it = head;
  for (size_t i = 0; i < position; ++i) {
    it = it->next;
  }
  return it;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::search_backward(const size_t &position) const {
  if (position >= list_size) return nullptr;

  Node<T> *it = tail;
  for (size_t i = list_size - 1; i > position; --i) {
    it = it->prev;
  }
  return it;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
  for (Node<T>* it = head; it; it = it->next) {
    std::cout << it->data << " ";
  }
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
  assert(list_size > 0);
  Node<T> *temp = head;
  head = head->next;
  list_size--;
  delete temp;
  if (head != nullptr) head->prev = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
  assert(list_size > 0);
  Node<T> *temp = tail;
  tail = tail->prev;
  delete temp;
  list_size--;
  if (tail != nullptr) tail->next = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::remove_at(const size_t& position) {
  assert(position >= 0 && position < list_size);
  if (position == list_size - 1) return pop_back();
  if (position == 0) return pop_front();

  Node<T> *target_node = (position < list_size / 2) ? search_forward(position):search_backward(position);
  const T data = target_node->data;
  target_node->prev->next = target_node->next;
  target_node->next->prev = target_node->prev;
  list_size--;
  delete target_node;
}

template <typename T>
void DoublyLinkedList<T>::remove_node(Node<T> *target_node) {
  assert(target_node != nullptr && list_size > 0);
  if (target_node == head) return pop_front();
  if (target_node == tail) return pop_back();

  target_node->next->prev = target_node->prev;
  target_node->prev->next = target_node->next;
  delete target_node;
  list_size--;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
  while (head != nullptr) {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }

  tail = nullptr;
  list_size = 0;
}

template <typename T>
T& DoublyLinkedList<T>::operator[](const size_t &position) const {
  assert(position >= 0 && position < list_size);
  Node<T> *positionNode = position < list_size / 2 ? search_forward(position):search_backward(position);
  return positionNode->data;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::get_head() {
  return head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::get_tail() {
  return tail;
}

template <typename T>
T& DoublyLinkedList<T>::front() {
  assert(list_size > 0);
  return head;
}

template <typename T>
T& DoublyLinkedList<T>::back() {
  assert(list_size > 0);
  return tail;
}