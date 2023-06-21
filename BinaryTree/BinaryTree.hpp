#pragma once

/*
 * Binary tree implementation
 */

struct Node
{
  long data;
  Node *left;
  Node *right;
  Node(long d = 0, Node *l = nullptr, Node *r = nullptr) : data(d), left(l), right(r) {}
};

class BinaryTree
{
private:
  Node *root;
  size_t _size;

public:
  BinaryTree() : _size(0), root(nullptr) {}
  ~BinaryTree();
  size_t size() const;
  size_t height() const;
  bool exist(const long) const;
  void display() const;
  void insert(const long);
  void remove(const long);
  void clear();
  long getRoot() const;

private:
  void display(Node *) const;
  void insert(Node *&, const long);
  size_t height(Node *) const;
  Node *search_node(Node *, const long) const;
  Node *search_parent_node(Node *, const long) const;
  void clear(Node *&);
};