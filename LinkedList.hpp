#pragma once

// The node structure
struct Node
{
    double data;
    Node *next;
    Node *prev;

    // Constructor initializes the node
    Node(double value, Node *n = nullptr, Node *p = nullptr) : next(n), prev(p), data(value) {}
};

// The doubly linkedlist class
class LinkedList
{
    Node *head;
    Node *tail;
    size_t length;
public:
    LinkedList();
    ~LinkedList();
    size_t size();
    void push_front(const double);
    void push_back(const double);
    void insert(const size_t, const double);
    double pop_front();
    double pop_back();
    double remove(const size_t);
    void print();
    void clear();
    double &operator[](const size_t);
private:
    Node *search_forward(const size_t);
    Node *search_backward(const size_t);
};
