#include <iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

// Destructor clears the list

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

// Method returns the number of elements in the list

template <typename T>
size_t LinkedList<T>::size() const
{
    return length;
}

// Method to insert an element at the beginning of the list

template <typename T>
void LinkedList<T>::push_front(const T data)
{
    Node<T> *newNode = new Node<T>(data, head);

    length == 0 ? tail = newNode : head->prev = newNode;
    head = newNode;
    length++;
}

// Method to insert an element at the end of the list

template <typename T>
void LinkedList<T>::push_back(const T data)
{
    Node<T> *newNode = new Node<T>(data, nullptr, tail);

    length == 0 ? head = newNode : tail->next = newNode;
    tail = newNode;
    length++;
}

// Method to insert an element at specific position in the list, O(min(position, length - position))

template <typename T>
void LinkedList<T>::insert(const size_t position, const T data)
{
    if (position > length) { throw out_of_range("Index out of bounds."); }
    if (position == 0) { return push_front(data); }
    if (position == length) { return push_back(data); }

    Node<T> *positionNode = position < length / 2 ? search_forward(position) : search_backward(position);
    Node<T> *newNode = new Node<T>(data, positionNode, positionNode->prev);

    positionNode->prev->next = newNode;
    positionNode->prev = newNode;
    length++;
}

// Method to search for an element at the head of the list

template <typename T>
Node<T>* LinkedList<T>::search_forward(const size_t position) const
{
    if (position >= length) { return nullptr; }

    Node<T> *iterator = head;

    for (size_t i = 0; i < position; ++i)
    {
        iterator = iterator->next;
    }

    return iterator;
}

// Method to search for an element at the tail of the list

template <typename T>
Node<T>* LinkedList<T>::search_backward(const size_t position) const
{
    if (position >= length) { return nullptr; }

    Node<T> *iterator = tail;

    for (size_t i = length - 1; i > position; --i)
    {
        iterator = iterator->prev;
    }

    return iterator;
}

// Method to print all list elements

template <typename T>
void LinkedList<T>::print() const
{
    Node<T> *iterator = head;

    cout << "{";

    while (iterator)
    {
        cout << " " << iterator->data;
        iterator = iterator->next;
    }

    cout << " }";
}

// Method to remove an element at the beginning of the list

template <typename T>
T LinkedList<T>::pop_front()
{
    if (head == nullptr) { throw out_of_range("List is empty"); }

    T data = head->data;
    Node<T> *temp = head;

    head = head->next;
    delete temp;
    length--;

    if (head != nullptr) { head->prev = nullptr; }

    return data;
}

// Method to remove an element at the end of the list

template <typename T>
T LinkedList<T>::pop_back()
{
    if (tail == nullptr) { throw out_of_range("List is empty"); }

    T data = tail->data;
    Node<T> *temp = tail;

    tail = tail->prev;
    delete temp;
    length--;

    if (tail != nullptr) { tail->next = nullptr; }

    return data;
}

// Method to remove an element at specific position

template <typename T>
T LinkedList<T>::remove(const size_t position)
{
    if (position >= length) { throw out_of_range("Index out of bounds."); }
    if (position == 0) { return pop_front(); }
    if (position == length-1) { return pop_back(); }

    Node<T> *positionNode = (position < length / 2) ? search_forward(position) : search_backward(position);
    T data = positionNode->data;

    positionNode->prev->next = positionNode->next;
    positionNode->next->prev = positionNode->prev;
    delete positionNode;
    length--;

    return data;
}

// Method clears the list

template <typename T>
void LinkedList<T>::clear()
{
    while (head != nullptr)
    {
        Node<T> *temp = head->next;
        delete head;
        head = temp;
    }

    tail = nullptr;
    length = 0;
}

// Method to access an element at specific position

template <typename T>
T& LinkedList<T>::operator[](const size_t position) const
{
    if (position >= length) { throw out_of_range("Index out of bounds."); }

    Node<T> *positionNode = position < length / 2 ? search_forward(position) : search_backward(position);

    return positionNode->data;
}

/**/
