#include <iostream>
#include "linkedList.hpp"
using namespace std;

// Constructor initializes the list to be empty
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

// Destructor clears the list
LinkedList::~LinkedList() {
    this->clear();
}

// Method returns the number of elements in the list
size_t LinkedList::size() {
    return this->length;
}

// Method to insert an element at the beginning of the list
void LinkedList::push_front(const double data)
{
    Node *new_node = new Node(data, head);

    (length == 0) ? tail = new_node : head->prev = new_node;
    head = new_node;

    ++length;
}

// Method to insert an element at the end of the list
void LinkedList::push_back(const double data)
{
    Node *new_node = new Node(data, nullptr, tail);

    (length == 0) ? head = new_node : tail->next = new_node;
    tail = new_node;

    ++length;
}

// Method to insert an element at specific position in the list, O(min(position, length - position))
void LinkedList::insert(const size_t position, const double data)
{
    if (position > length) { throw out_of_range("Index out of bounds."); }
    
    if (position == 0)
    {
        push_front(data);
        return;
    }

    Node *position_node = position < length / 2 ? search_forward(position) : search_backward(position);
    Node *new_node = new Node(data, position_node, position_node->prev);
    
    position_node->prev = new_node;
    position_node->prev->next = new_node;

    ++length;
}

// Method to search for an element at the head of the list
Node* LinkedList::search_forward(const size_t position)
{
    if (position >= length) { return nullptr; }

    Node *pointer = head;

    for (size_t i = 0; i < position; ++i) {
        pointer = pointer->next;
    }

    return pointer;
}

// Method to search for an element at the tail of the list
Node* LinkedList::search_backward(const size_t position)
{
    if (position >= length) { return nullptr; }

    Node *pointer = tail;

    for (size_t i = length - 1; i > position; --i) {
	    pointer = pointer->prev;
    }

    return pointer;
}

// Method to print all list elements
void LinkedList::print()
{
    Node *pointer = head;
    
    cout << "{";
    
    while (pointer)
    {
	    cout << " " << pointer->data;
	    pointer = pointer->next;
    }

    cout << " }";
}

// Method to remove an element at the beginning of the list
double LinkedList::pop_front()
{
    if (head == nullptr) { return -1; }
    
    double data = head->data;
    Node *pointer = head;

    head = head->next;
    if (head) { head->prev = nullptr; }

    delete pointer;
    --length;

    return data;
}

// Method to remove an element at the end of the list
double LinkedList::pop_back()
{
    if (tail == nullptr) { return -1; }

    double data = tail->data;
    Node *pointer = tail;

    tail = tail->prev;

    if (tail) { tail->next = nullptr; }
    
    delete pointer;
    --length;

    return data;
}

// Method to remove an element at specific position
double LinkedList::remove(const size_t position)
{
    if (position >= length) { throw out_of_range("Index out of bounds."); }

    Node *position_node = position < length / 2 ? search_forward(position) : search_backward(position);

    if (position_node == head) { return pop_front(); }
    if (position_node == tail) { return pop_back();  }
    
    double data = position_node->data;

    position_node->prev->next = position_node->next;
    position_node->next->prev = position_node->prev;
    
    delete position_node;    
    --length;

    return data;
}

// Method clears the list
void LinkedList::clear()
{
    while (head != nullptr)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }

    tail = nullptr;
    length = 0;
}

// Method to access an element at specific position
double &LinkedList::operator[](const size_t position)
{
    if (position >= length) { throw out_of_range("Index out of bounds."); }

    Node *position_node = position < length / 2 ? search_forward(position) : search_backward(position);
    return position_node->data;
}
