#include <iostream>
#include "SinglyLinkedList.hpp"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    length = 0;
}

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

    head = newNode;
    length++;
}

// Method to insert an element at the end of the list

template <typename T>
void LinkedList<T>::push_back(const T data)
{
    if (length == 0) { return push_front(data); }

    Node<T> *iterator = head;

    while (iterator->next != nullptr)
    {
        iterator = iterator->next;
    }

    iterator->next = new Node<T>(data);
    length++;
}

// Method to insert an element at specific position in the list, O(position)

template <typename T>
void LinkedList<T>::insert(const size_t position, const T data)
{
    if (position > length) { throw out_of_range("Index out of bounds."); }
    if (position == 0) { return push_front(data); }
    if (position == length) { return push_back(data); }

    Node<T> *iterator = head;

    for (size_t i = 0; i < position - 1; ++i)
    {
        iterator = iterator->next;
    }

    iterator->next = new Node<T>(data, iterator->next);
    length++;
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
    if (length == 0) { throw out_of_range("List is empty"); }

    T data = head->data;
    Node<T> *temp = head;

    head = head->next;
    length--;
    delete temp;

    return data;
}

// Method to remove an element at the end of the list

template <typename T>
T LinkedList<T>::pop_back()
{
    switch (length)
    {
        case 0: throw out_of_range("List is empty");
        case 1: return pop_front();
    }

    Node<T> *iterator = head;

    while (iterator->next && iterator->next->next)
    {
        iterator = iterator->next;
    }

    T data = iterator->next->data;

    delete iterator->next;
    iterator->next = nullptr;
    length--;

    return data;
}

// Method to remove an element at specific position

template <typename T>
T LinkedList<T>::remove(const size_t position)
{
    if (position >= length) { throw out_of_range("Index out of range"); }
    if (position == 0) { return pop_front(); }
    if (position == length-1) { return pop_back(); }

    Node<T> *iterator = head;

    for (size_t i = 0; i < position - 1; ++i)
    {
        iterator = iterator->next;
    }

    Node<T> *temp = iterator->next;
    T data = iterator->data;

    iterator->next = iterator->next->next;
    length--;
    delete temp;

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

    length = 0;
}

// Method to access an element at specific position

template <typename T>
T& LinkedList<T>::operator[](const size_t position) const
{
    if (position >= length) { throw out_of_range("Index out of bounds."); }

    Node<T> *iterator = head;

    for (size_t i = 0; i < position; ++i)
    {
        iterator = iterator->next;
    }

    return iterator->data;
}

/**/
