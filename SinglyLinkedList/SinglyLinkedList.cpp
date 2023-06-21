#include <iostream>
#include <stdexcept>
#include "SinglyLinkedList.hpp"
using namespace std;

// Destructor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
  clear();
}

// Return the number of elements
template <typename T>
size_t SinglyLinkedList<T>::size() const
{
  return listSize;
}

// Insert element at the beginning of the list
template <typename T>
void SinglyLinkedList<T>::push_front(const T data)
{
  Node<T> *newNode = new Node<T>(data, head);
  head = newNode;
  listSize++;
}

// Insert element at the end of the list
template <typename T>
void SinglyLinkedList<T>::push_back(const T data)
{
  if (listSize == 0)
    return push_front(data);

  Node<T> *it = head;
  while (it->next != nullptr)
    it = it->next;

  it->next = new Node<T>(data);
  listSize++;
}

// Insert element at specific position, O(position)
template <typename T>
void SinglyLinkedList<T>::insert(const size_t position, const T data)
{
  if (position >= listSize)
    throw runtime_error("Index out of bounds");
  else if (position == 0)
    return push_front(data);

  Node<T> *it = head;
  for (size_t i = 0; i < position - 1; ++i)
    it = it->next;

  it->next = new Node<T>(data, it->next);
  listSize++;
}

// display all list elements
template <typename T>
void SinglyLinkedList<T>::display() const
{
  for (Node<T> *it = head; it != nullptr; it = it->next)
    cout << " " << it->data;
}

// Remove element from the beginning of the list
template <typename T>
T SinglyLinkedList<T>::pop_front()
{
  if (listSize == 0)
    throw runtime_error("List is empty");

  Node<T> *temp = head;
  const T data = temp->data;
  head = head->next;
  listSize--;
  delete temp;

  return data;
}

// Remove element from the end of the list
template <typename T>
T SinglyLinkedList<T>::pop_back()
{
  if (listSize == 0)
    throw runtime_error("List is empty");
  else if (listSize == 1)
    return pop_front();

  Node<T> *it = head;
  while (it->next && it->next->next)
    it = it->next;

  const T data = it->next->data;
  delete it->next;
  it->next = nullptr;
  listSize--;

  return data;
}

// Remove position-th element from list
template <typename T>
T SinglyLinkedList<T>::remove(const size_t position)
{
  if (position >= listSize)
    throw runtime_error("Index out of bounds");
  else if (position == 0)
    return pop_front();
  else if (position == listSize - 1)
    return pop_back();

  Node<T> *it = head;
  for (size_t i = 0; i < position - 1; ++i)
    it = it->next;

  Node<T> *temp = it->next;
  const T data = it->data;
  it->next = it->next->next;
  listSize--;
  delete temp;

  return data;
}

// Clearing the list
template <typename T>
void SinglyLinkedList<T>::clear()
{
  while (head != nullptr)
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }
  listSize = 0;
}

// Access the position-th element
template <typename T>
T &SinglyLinkedList<T>::operator[](const size_t position) const
{
  if (position >= listSize)
    throw runtime_error("Index out of bounds");

  Node<T> *it = head;
  for (size_t i = 0; i < position; ++i)
    it = it->next;

  return it->data;
}