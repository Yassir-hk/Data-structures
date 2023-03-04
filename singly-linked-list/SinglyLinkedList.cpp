#include <iostream>
#include <stdexcept>
#include "SinglyLinkedList.hpp"
using namespace std;


// Destructor
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

// Return the number of elements
template <class T>
size_t SinglyLinkedList<T>::size() const {
    return _size;
}

// Insert element at the beginning of the list
template <class T>
void SinglyLinkedList<T>::push_front(const T data)
{
    Node<T> *newNode = new Node<T>(data, head);
    head = newNode;
    _size++;
}

// Insert element at the end of the list
template <class T>
void SinglyLinkedList<T>::push_back(const T data)
{
    if (_size == 0) {
        return push_front(data);
    }

    Node<T> *iterator = head;
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }

    iterator->next = new Node<T>(data);
    _size++;
}

// Insert element at specific position, O(position)
template <class T>
void SinglyLinkedList<T>::insert(const size_t position, const T data)
{
    if (position >= _size) {
        throw runtime_error("Index out of bounds"); 
    }
    else if (position == 0) {
        return push_front(data);
    }

    Node<T> *iterator = head;
    for (size_t i = 0; i < position - 1; ++i) {
        iterator = iterator->next;
    }

    iterator->next = new Node<T>(data, iterator->next);
    _size++;
}

// Print all list elements
template <class T>
void SinglyLinkedList<T>::print() const
{
    cout << "{";

    for (Node<T> *it = head; it != nullptr; it = it->next) {
        cout << " " << it->data;
    }

    cout << " }";
}

// Remove element from the beginning of the list
template <class T>
T SinglyLinkedList<T>::pop_front()
{
    if (_size == 0) {
        throw runtime_error("List is empty");
    }

    Node<T> *temp = head;
    const T data = temp->data;
    head = head->next;
    _size--;
    delete temp;

    return data;
}

// Remove element from the end of the list
template <class T>
T SinglyLinkedList<T>::pop_back()
{
    switch (_size)
    {
        case 0: throw runtime_error("List is empty");
        case 1: return pop_front();
    }

    Node<T> *iterator = head;
    while (iterator->next && iterator->next->next) {
        iterator = iterator->next;
    }

    const T data = iterator->next->data;
    delete iterator->next;
    iterator->next = nullptr;
    _size--;

    return data;
}

// Remove position-th element from list
template <class T>
T SinglyLinkedList<T>::remove(const size_t position)
{
    if (position >= _size) {
        throw runtime_error("Index out of bounds");
    }
    else if (position == 0) {
        return pop_front();
    }
    else if (position == _size-1) {
        return pop_back();
    }

    Node<T> *iterator = head;
    for (size_t i = 0; i < position - 1; ++i) {
        iterator = iterator->next;
    }

    Node<T> *temp = iterator->next;
    const T data = iterator->data;
    iterator->next = iterator->next->next;
    _size--;
    delete temp;
    return data;
}

// Clearing the list
template <class T>
void SinglyLinkedList<T>::clear()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    _size = 0;
}

// Access the position-th element
template <class T>
T& SinglyLinkedList<T>::operator[](const size_t position) const
{
    if (position >= _size) {
        throw runtime_error("Index out of bounds");
    }

    Node<T> *iterator = head;    
    for (size_t i = 0; i < position; ++i) {
        iterator = iterator->next;
    }

    return iterator->data;
}