#include <iostream>
#include <stdexcept>
#include "CircularDoublyLinkedList.hpp"
using namespace std;

// Destructor
template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    clear();
}

// Return the number of elements in the list
template <class T>
size_t CircularDoublyLinkedList<T>::size() const {
    return _size;
}

// Display all list elements
template <class T>
void CircularDoublyLinkedList<T>::display() const
{
    cout << "{";

    for (auto it = sentinel.next; it != &sentinel; it = it->next) {
        cout << " " << it->data;
    }

    cout << " }\n";
}

// Insert a element to the beginning of the list
template <class T>
void CircularDoublyLinkedList<T>::push_front(const T& data)
{
    sentinel.next = new Node<T>(data, sentinel.next, &sentinel);
    _size++;
    
    if (_size == 1) {
        sentinel.prev = sentinel.next;
    }
}

// Insert element to the end of the list
template <class T>
void CircularDoublyLinkedList<T>::push_back(const T& data)
{
    if (_size == 0) {
        return push_front(data);
    }

    Node<T> *nodeToInsert = new Node<T>(data, &sentinel, sentinel.prev);
    sentinel.prev->next = nodeToInsert;
    sentinel.prev = nodeToInsert;
    _size++;
}

// Deleting a node from the beginning of the list
template <class T>
void CircularDoublyLinkedList<T>::pop_front()
{
    if (_size == 0) {
        throw runtime_error("Deleting from empty list");
    }

    Node<T> *temp = sentinel.next;
    sentinel.next = sentinel.next->next;
    sentinel.next->prev = &sentinel;
    delete temp;    
    _size--;
}

// Delete node from the end of the list
template <class T>
void CircularDoublyLinkedList<T>::pop_back()
{
    if (_size < 2) {
        return pop_front();
    }

    Node<T> *temp = sentinel.prev;
    sentinel.prev = sentinel.prev->prev;
    sentinel.prev->next = &sentinel;
    delete temp;
    _size--;
}

// Delete all list elements
template <class T>
void CircularDoublyLinkedList<T>::clear()
{
    while (_size) {
        pop_front();
    }
}

// Return node of specific value
template <class T>
Node<T>* CircularDoublyLinkedList<T>::search_node(const T& data) const
{
    for (auto it = sentinel.next; it != &sentinel; it = it->next)
    {
        if (data == it->data) {
            return it;
        }
    }

    return nullptr;
}

// Return position-th node, searching on the right direction
template <class T>
Node<T>* CircularDoublyLinkedList<T>::search_forward(const size_t position) const
{
    if (position >= _size) {
        return nullptr;
    }

    for (auto it = sentinel.next, i = 0; i < position; ++i) {
        it = it->next;
    }

    return it;
}

// Return position-th node, searching in the left direction
template <class T>
Node<T>* CircularDoublyLinkedList<T>::search_backward(const size_t position) const
{
    if (position >= _size) {
        return nullptr;
    }

    for (auto it = sentinel.prev, i = _size-1; i > position; --i) {
        it = it->prev;
    }

    return it;
}

// Return value of the first node
template <class T>
T& CircularDoublyLinkedList<T>::front() const
{
    if (_size == 0) {
        throw runtime_error("The list is empty");
    }
    
    return sentinel.next->data;
}

// Return value of the last node
template <class T>
T& CircularDoublyLinkedList<T>::back() const
{
    if (_size == 0) {
        throw runtime_error("The list is empty");
    }
    
    return sentinel.prev->data;
}

// Insert element at specific position
template <class T>
void CircularDoublyLinkedList<T>::insert_at(const T& data, const size_t position)
{
    if (position >= _size) {
        throw runtime_error("Index out of bound");
    }
    else if (position == 0) {
        return push_front(data);
    }

    Node<T> *positionNode = position < _size / 2 ? search_forward(position) : search_backward(position);
    Node<T> *nodeToInsert = new Node<T>(data, positionNode, positionNode->prev);
    positionNode->prev->next = nodeToInsert;
    positionNode->prev = nodeToInsert;
    _size++;
}

// Remove the position-th element
template <class T>
void CircularDoublyLinkedList<T>::remove_at(const size_t position)
{
    if (position >= _size) {
        throw runtime_error("Index out of bound");
    }
    else if (position == 0) {
        return pop_front();
    }
    else if (position == _size - 1) {
        return pop_back();
    }

    Node<T> *positionNode = position < _size / 2 ? search_forward(postion) : search_backward(position);
    positionNode->prev->next = positionNode->next;
    positionNode->next->prev = positionNode->prev;
    _size--;
    delete positionNode;
}