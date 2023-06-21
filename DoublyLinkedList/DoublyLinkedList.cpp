#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.hpp"
using namespace std;

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  clear();
}

// Return the number of elements in the list
template <typename T>
size_t DoublyLinkedList<T>::size() const
{
  return listSize;
}

// Insert element at the beginning of the list
template <typename T>
void DoublyLinkedList<T>::push_front(const T &data)
{
  Node<T> *nodeToInsert = new Node<T>(data, head);
  listSize == 0 ? tail = nodeToInsert : head->prev = nodeToInsert;
  head = nodeToInsert;
  listSize++;
}

// Insert element at the end of the list
template <typename T>
void DoublyLinkedList<T>::push_back(const T &data)
{
  Node<T> *nodeToInsert = new Node<T>(data, nullptr, tail);
  listSize == 0 ? head = nodeToInsert : tail->next = nodeToInsert;
  tail = nodeToInsert;
  listSize++;
}

// Insert an element at specific position in the list, O(min(position, listSize - position))
template <typename T>
void DoublyLinkedList<T>::insert(const size_t &position, const T &data)
{
  if (position >= listSize)
    throw runtime_error("Index out of bounds");
  else if (position == 0)
    return push_front(data);

  Node<T> *positionNode = position < listSize / 2 ? search_forward(position) : search_backward(position);
  Node<T> *nodeToInsert = new Node<T>(data, positionNode, positionNode->prev);
  positionNode->prev->next = nodeToInsert;
  positionNode->prev = nodeToInsert;
  listSize++;
}

// Search for element exploring right direction
template <typename T>
Node<T> *DoublyLinkedList<T>::search_forward(const size_t &position) const
{
  if (position >= listSize)
    return nullptr;

  Node<T> *it = head;
  for (size_t i = 0; i < position; ++i)
    it = it->next;

  return it;
}

// Search for element exploring the left direction
template <typename T>
Node<T> *DoublyLinkedList<T>::search_backward(const size_t &position) const
{
  if (position >= listSize)
    return nullptr;

  Node<T> *it = tail;
  for (size_t i = listSize - 1; i > position; --i)
    it = it->prev;

  return it;
}

// display all list elements
template <typename T>
void DoublyLinkedList<T>::display() const
{
  for (auto it = head; it; it = it->next)
    cout << " " << it->data;
}

// Remove element from the beginning of the list
template <typename T>
T DoublyLinkedList<T>::pop_front()
{
  if (listSize == 0)
    throw runtime_error("List is empty");

  T data = head->data;
  Node<T> *temp = head;
  head = head->next;
  listSize--;
  delete temp;

  if (head != nullptr)
    head->prev = nullptr;

  return data;
}

// Remove element from the end of the list
template <typename T>
T DoublyLinkedList<T>::pop_back()
{
  if (listSize == 0)
    throw runtime_error("List is empty");

  Node<T> *temp = tail;
  const T data = temp->data;
  tail = tail->prev;
  listSize--;
  delete temp;

  if (tail != nullptr)
    tail->next = nullptr;

  return data;
}

// Remove the position-th element
template <typename T>
T DoublyLinkedList<T>::remove_at(const size_t &position)
{
  if (position >= listSize)
    throw runtime_error("Index out of bounds");
  else if (position == listSize - 1)
    return pop_back();
  else if (position == 0)
    return pop_front();

  Node<T> *positionNode = (position < listSize / 2) ? search_forward(position) : search_backward(position);
  const T data = positionNode->data;
  positionNode->prev->next = positionNode->next;
  positionNode->next->prev = positionNode->prev;
  listSize--;
  delete positionNode;

  return data;
}

// Clearing the list
template <typename T>
void DoublyLinkedList<T>::clear()
{
  while (head != nullptr)
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }

  tail = nullptr;
  listSize = 0;
}

// Access index-th element
template <typename T>
T &DoublyLinkedList<T>::operator[](const size_t &position) const
{
  if (position >= listSize)
    throw runtime_error("Index out of bound");

  Node<T> *positionNode = position < listSize / 2 ? search_forward(position) : search_backward(position);
  return positionNode->data;
}