#pragma once
#include <cstddef>

template<typename T>
struct Node {
  T data;
  Node<T> *left;
  Node<T> *right;
  Node(T d = 0, Node *l = nullptr, Node *r = nullptr) {
    data = d;
    left = l;
    right = r;
  }
};

template<typename T>
class BinaryTree {
private:
  Node<T> *root;
  size_t tree_size;
  int (*compare)(T, T);
  void clear(Node<T>*&);
  void insert(Node<T>*&, const T);
  void inorder_traversal(Node<T>*&) const;
  void preorder_traversal(Node<T>*&) const;
  void postorder_traversal(Node<T>*&) const;
  size_t height(Node<T>*&) const;
  Node<T>*& find(Node<T>*& node, const T data) const;

public:
  BinaryTree(int (*comp)(T, T));
  ~BinaryTree();
  size_t size() const;
  size_t height() const;
  bool exist(const T) const;
  void insert(const T);
  void remove(const T);
  void clear();
  void inorder_traversal() const;
  void preorder_traversal() const;
  void postorder_traversal() const;
};

#include "../sources/BinaryTree.cpp"