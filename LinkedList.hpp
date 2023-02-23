#pragma once

// The node structure
template<typename TYPE>

struct Node
{
    TYPE data;
    Node<TYPE> *next;
    Node<TYPE> *prev;

    // Constructor initializes the node
    Node(TYPE value, Node *n = nullptr, Node *p = nullptr) : next(n), prev(p), data(value) {}
};

// The doubly linkedlist class
template<typename TYPE>

class LinkedList
{
    Node<TYPE> *head;
    Node<TYPE> *tail;
    size_t length;
public:
    LinkedList();
    ~LinkedList();
    size_t size() const;
    void push_front(const TYPE);
    void push_back(const TYPE);
    void insert(const size_t, const TYPE);
    TYPE pop_front();
    TYPE pop_back();
    TYPE remove(const size_t);
    void print() const;
    void clear();
    TYPE &operator[](const size_t);
private:
    Node<TYPE> *search_forward(const size_t)  const;
    Node<TYPE> *search_backward(const size_t) const;
};
