#pragma once

// The node structure

template<typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T d, Node *n = nullptr) : next(n), data(d) {}
};

// The doubly linkedlist class

template<typename T>
class LinkedList
{
    Node<T> *head;
    size_t length;
public:
    LinkedList();
    ~LinkedList();
    size_t size() const;
    void push_front(const T);
    void push_back(const T);
    void insert(const size_t, const T);
    T pop_front();
    T pop_back();
    T remove(const size_t);
    void print() const;
    void clear();
    T& operator[](const size_t) const;
};

/**/
