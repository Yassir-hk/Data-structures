#pragma once

/*
 * Circular doubly linked list implementation
 */

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T d, Node<T> *n = nullptr, Node <T> *p = nullptr) : data(d), next(n), prev(p) {}
};

template <class T>
class CircularDoublyLinkedList
{
private:
    Node<T> sentinel;
    size_t _size;
public:
    CircularDoublyLinkedList() : _size(0) {
        sentinel.next = &sentinel;
        sentinel.prev = &sentinel;
    };
    ~CircularDoublyLinkedList();
    T& back() const;
    T& front() const;
    void display() const;
    void push_back(const T&);
    void push_front(const T&);
    void insert_at(const T&, const size_t);
    void remove_at(const size_t);
    void pop_front();
    void pop_back();
    void clear();
    size_t size() const;
    Node<T>* search_node(const T&) const;
    Node<T>* search_forward(const size_t) const;
    Node<T>* search_backward(const size_t) const;
};