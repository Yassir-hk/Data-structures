#include <cassert>
#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;


// Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

// Return the number of elements in the list
template <class T>
size_t DoublyLinkedList<T>::size() const {
    return _size;
}

// Insert element at the beginning of the list
template <class T>
void DoublyLinkedList<T>::push_front(const T& data)
{
    Node<T> *nodeToInsert = new Node<T>(data, head);
    _size == 0 ? tail = nodeToInsert : head->prev = nodeToInsert;
    head = nodeToInsert;
    _size++;
}

// Insert element at the end of the list
template <class T>
void DoublyLinkedList<T>::push_back(const T& data)
{
    Node<T> *nodeToInsert = new Node<T>(data, nullptr, tail);
    _size == 0 ? head = nodeToInsert : tail->next = nodeToInsert;
    tail = nodeToInsert;
    _size++;
}

// Insert an element at specific position in the list, O(min(position, _size - position))
template <class T>
void DoublyLinkedList<T>::insert(const size_t& position, const T& data)
{
    if (position >= _size) {
        throw runtime_error("Index out of bounds");
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

// Search for element exploring right direction
template <class T>
Node<T>* DoublyLinkedList<T>::search_forward(const size_t& position) const
{
    if (position >= _size) {
        return nullptr;
    }

    Node<T> *iterator = head;

    for (size_t i = 0; i < position; ++i) {
        iterator = iterator->next;
    }

    return iterator;
}

// Search for element exploring the left direction
template <class T>
Node<T>* DoublyLinkedList<T>::search_backward(const size_t& position) const
{
    if (position >= _size) {
        return nullptr;
    }

    Node<T> *iterator = tail;

    for (size_t i = _size - 1; i > position; --i) {
        iterator = iterator->prev;
    }

    return iterator;
}

// Print all list elements
template <class T>
void DoublyLinkedList<T>::print() const
{
    cout << "{";

    for (auto it = head; it; it = it->next) {
        cout << " " << it->data;
    }

    cout << " }";
}

// Remove element from the beginning of the list
template <class T>
T DoublyLinkedList<T>::pop_front()
{
    if (_size == 0) {
        throw runtime_error("List is empty");
    }

    T data = head->data;
    Node<T> *temp = head;
    head = head->next;
    _size--;
    delete temp;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    return data;
}

// Remove element from the end of the list
template <class T>
T DoublyLinkedList<T>::pop_back()
{
    if (_size == 0) {
        throw runtime_error("List is empty");
    }

    Node<T> *temp = tail;
    const T data = temp->data;
    tail = tail->prev;
    _size--;
    delete temp;

    if (tail != nullptr) {
        tail->next = nullptr;
    }

    return data;
}

// Remove the position-th element
template <class T>
T DoublyLinkedList<T>::remove_at(const size_t& position)
{
    if (position >= _size) {
        throw runtime_error("Index out of bounds");
    }
    else if (position == _size-1) {
        return pop_back();
    }
    else if (position == 0) {
        return pop_front();
    }

    Node<T> *positionNode = (position < _size / 2) ? search_forward(position) : search_backward(position);
    const T data = positionNode->data;    
    positionNode->prev->next = positionNode->next;
    positionNode->next->prev = positionNode->prev;
    _size--;
    delete positionNode;    
    return data;
}

// Clearing the list
template <class T>
void DoublyLinkedList<T>::clear()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    _size = 0;
}

// Access index-th element
template <class T>
T& DoublyLinkedList<T>::operator[](const size_t& position) const
{
    if (position >= _size) {
        throw runtime_error("Index out of bound");
    }

    Node<T> *positionNode = position < _size / 2 ? search_forward(position) : search_backward(position);
    return positionNode->data;
}