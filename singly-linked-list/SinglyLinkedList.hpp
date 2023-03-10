#pragma once

/*
 * Singly linked list implementation
 */

template<typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T d, Node *n = nullptr) : next(n), data(d) {}
};

template<typename T>
class SinglyLinkedList
{
    Node<T> *head;
    size_t _size;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {};
    ~SinglyLinkedList();
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
