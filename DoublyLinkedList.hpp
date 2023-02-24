#pragma once

template<typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T value, Node *n = nullptr, Node *p = nullptr) : next(n), prev(p), data(value) {}
};

template<typename T>
class LinkedList
{
    Node<T> *head;
    Node<T> *tail;
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
private:
    Node<T>* search_forward(const size_t)  const;
    Node<T>* search_backward(const size_t) const;
};

/**/
