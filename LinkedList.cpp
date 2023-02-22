#include <iostream>
#include "linkedList.hpp"

// Constructor initializes the list to be empty
template<typename TYPE>

LinkedList<TYPE>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

// Destructor clears the list
template<typename TYPE>

LinkedList<TYPE>::~LinkedList() {
    this->clear();
}

// Method returns the number of elements in the list
template<typename TYPE>

size_t LinkedList<TYPE>::size() {
    return this->length;
}

// Method to insert an element at the beginning of the list
template<typename TYPE>

void LinkedList<TYPE>::push_front(const TYPE data)
{
    Node<TYPE> *new_node = new Node<TYPE>(data, head);

    (length == 0) ? tail = new_node : head->prev = new_node;
    head = new_node;

    ++length;
}

// Method to insert an element at the end of the list
template<typename TYPE>

void LinkedList<TYPE>::push_back(const TYPE data)
{
    Node<TYPE> *new_node = new Node<TYPE>(data, nullptr, tail);

    (length == 0) ? head = new_node : tail->next = new_node;
    tail = new_node;

    ++length;
}

// Method to insert an element at specific position in the list, O(min(position, length - position))
template<typename TYPE>

void LinkedList<TYPE>::insert(const size_t position, const TYPE data)
{
    if (position > length) { throw out_of_range("Index out of bounds."); }
    
    if (position == 0)
    {
        push_front(data);
        return;
    }

    Node<TYPE> *position_node = position < length / 2 ? search_forward(position) : search_backward(position);
    Node<TYPE> *new_node = new Node<TYPE>(data, position_node, position_node->prev);
    
    position_node->prev = new_node;
    position_node->prev->next = new_node;

    ++length;
}

// Method to search for an element at the head of the list
template<typename TYPE>

Node<TYPE>* LinkedList<TYPE>::search_forward(const size_t position)
{
    if (position >= length) { return nullptr; }

    Node<TYPE> *pointer = head;

    for (size_t i = 0; i < position; ++i) {
        pointer = pointer->next;
    }

    return pointer;
}

// Method to search for an element at the tail of the list
template<typename TYPE>

Node<TYPE>* LinkedList<TYPE>::search_backward(const size_t position)
{
    if (position >= length) { return nullptr; }

    Node<TYPE> *pointer = tail;

    for (size_t i = length - 1; i > position; --i) {
	    pointer = pointer->prev;
    }

    return pointer;
}

// Method to print all list elements
template<typename TYPE>

void LinkedList<TYPE>::print()
{
    Node<TYPE> *pointer = head;
    
    std::cout << "{";
    
    while (pointer)
    {
	    cout << " " << pointer->data;
	    pointer = pointer->next;
    }

    std::cout << " }";
}

// Method to remove an element at the beginning of the list
template<typename TYPE>

TYPE LinkedList<TYPE>::pop_front()
{
    if (head == nullptr) { return -1; }
    
    TYPE data = head->data;
    Node<TYPE> *pointer = head;

    head = head->next;
    if (head) { head->prev = nullptr; }

    delete pointer;
    --length;

    return data;
}

// Method to remove an element at the end of the list
template<typename TYPE>

TYPE LinkedList<TYPE>::pop_back()
{
    if (tail == nullptr) { return -1; }

    TYPE data = tail->data;
    Node<TYPE> *pointer = tail;

    tail = tail->prev;

    if (tail) { tail->next = nullptr; }
    
    delete pointer;
    --length;

    return data;
}

// Method to remove an element at specific position
template<typename TYPE>

TYPE LinkedList<TYPE>::remove(const size_t position)
{
    if (position >= length) { throw out_of_range("Index out of bounds."); }

    Node<TYPE> *position_node = position < length / 2 ? search_forward(position) : search_backward(position);

    if (position_node == head) { return pop_front(); }
    if (position_node == tail) { return pop_back();  }
    
    TYPE data = position_node->data;

    position_node->prev->next = position_node->next;
    position_node->next->prev = position_node->prev;
    
    delete position_node;    
    --length;

    return data;
}

// Method clears the list
template<typename TYPE>

void LinkedList<TYPE>::clear()
{
    while (head != nullptr)
    {
        Node<TYPE> *temp = head->next;
        delete head;
        head = temp;
    }

    tail = nullptr;
    length = 0;
}

// Method to access an element at specific position
template<typename TYPE>

TYPE &LinkedList<TYPE>::operator[](const size_t position)
{
    if (position >= length) { throw out_of_range("Index out of bounds."); }

    Node<TYPE> *position_node = position < length / 2 ? search_forward(position) : search_backward(position);
    return position_node->data;
}
