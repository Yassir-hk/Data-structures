#include <iostream>
#include <stdexcept>
#include "CircularLinkedList.hpp"
using namespace std;

// Destructor
template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
  clear();
}

// Return the number of elements in the list
template <typename T>
size_t CircularLinkedList<T>::size() const
{
  return listSize;
}

// Display all list elements
template <typename T>
void CircularLinkedList<T>::display() const
{
  for (auto it = sentinel.next; it != &sentinel; it = it->next)
    cout << " " << it->data;
}

// Insert a element to the beginning of the list
template <typename T>
void CircularLinkedList<T>::push_front(const T &data)
{
  sentinel.next = new Node<T>(data, sentinel.next, &sentinel);
  listSize++;

  if (listSize == 1)
    sentinel.prev = sentinel.next;
}

// Insert element to the end of the list
template <typename T>
void CircularLinkedList<T>::push_back(const T &data)
{
  if (listSize == 0)
    return push_front(data);

  Node<T> *nodeToInsert = new Node<T>(data, &sentinel, sentinel.prev);
  sentinel.prev->next = nodeToInsert;
  sentinel.prev = nodeToInsert;
  listSize++;
}

// Deleting a node from the beginning of the list
template <typename T>
void CircularLinkedList<T>::pop_front()
{
  if (listSize == 0)
    throw runtime_error("Deleting from empty list");

  Node<T> *temp = sentinel.next;
  sentinel.next = sentinel.next->next;
  sentinel.next->prev = &sentinel;
  delete temp;
  listSize--;
}

// Delete node from the end of the list
template <typename T>
void CircularLinkedList<T>::pop_back()
{
  if (listSize < 2)
    return pop_front();

  Node<T> *temp = sentinel.prev;
  sentinel.prev = sentinel.prev->prev;
  sentinel.prev->next = &sentinel;
  delete temp;
  listSize--;
}

// Delete all list elements
template <typename T>
void CircularLinkedList<T>::clear()
{
  while (listSize)
    pop_front();
}

// Return node of specific value
template <typename T>
Node<T> *CircularLinkedList<T>::search_node(const T &data) const
{
  for (auto it = sentinel.next; it != &sentinel; it = it->next)
    if (data == it->data)
      return it;

  return nullptr;
}

// Return position-th node, searching on the right direction
template <typename T>
Node<T> *CircularLinkedList<T>::search_forward(const size_t position) const
{
  if (position >= listSize)
    return nullptr;

  for (auto it = sentinel.next, i = 0; i < position; ++i)
    it = it->next;

  return it;
}

// Return position-th node, searching in the left direction
template <typename T>
Node<T> *CircularLinkedList<T>::search_backward(const size_t position) const
{
  if (position >= listSize)
    return nullptr;

  for (auto it = sentinel.prev, i = listSize - 1; i > position; --i)
    it = it->prev;

  return it;
}

// Return value of the first node
template <typename T>
T &CircularLinkedList<T>::front() const
{
  if (listSize == 0)
    throw runtime_error("The list is empty");

  return sentinel.next->data;
}

// Return value of the last node
template <typename T>
T &CircularLinkedList<T>::back() const
{
  if (listSize == 0)
    throw runtime_error("The list is empty");

  return sentinel.prev->data;
}

// Insert element at specific position
template <typename T>
void CircularLinkedList<T>::insert_at(const T &data, const size_t position)
{
  if (position >= listSize)
    throw runtime_error("Index out of bound");
  else if (position == 0)
    return push_front(data);

  Node<T> *positionNode = position < listSize / 2 ? search_forward(position) : search_backward(position);
  Node<T> *nodeToInsert = new Node<T>(data, positionNode, positionNode->prev);
  positionNode->prev->next = nodeToInsert;
  positionNode->prev = nodeToInsert;
  listSize++;
}

// Remove the position-th element
template <typename T>
void CircularLinkedList<T>::remove_at(const size_t position)
{
  if (position >= listSize)
    throw runtime_error("Index out of bound");
  else if (position == 0)
    return pop_front();
  else if (position == listSize - 1)
    return pop_back();

  Node<T> *positionNode = position < listSize / 2 ? search_forward(postion) : search_backward(position);
  positionNode->prev->next = positionNode->next;
  positionNode->next->prev = positionNode->prev;
  delete positionNode;
  listSize--;
}