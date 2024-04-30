#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
  T data;
  Node<T> *left;
  Node<T> *right;
  Node(T d = 0, Node *l = nullptr, Node *r = nullptr) : data(d), left(l), right(r) {}
};

template<typename T>
class BinaryTree {
private:
  Node<T> *root;
  size_t tree_size;
  int (*compare)(T, T);

public:
  BinaryTree(int (*comp)(T, T));
  ~BinaryTree();
  size_t size() const;
  size_t height() const;
  bool exist(const long) const;
  void print() const;
  void insert(const T);
  void remove(const T);
  void clear();
  long get_root();

private:
  void print(Node *) const;
  void insert(Node<T>*&, const T);
  size_t height(Node *) const;
  Node<T>* search_parent_node(Node<T>*, const T);
  Node<T>* remove(Node<T>*, const T);
  void clear(Node *&);
};

BinaryTree::~BinaryTree() {
  clear();
}

size_t BinaryTree::size() const {
  return treeSize;
}

void BinaryTree::print() const {
  print(root);
}

void BinaryTree::print(Node *exploredNode) const {
  if (exploredNode == nullptr) return;
  print(exploredNode->left);
  std::cout << " " << exploredNode->data;
  print(exploredNode->right);
}

size_t BinaryTree::height() const {
  return height(root);
}

size_t BinaryTree::height(Node *exploredNode) const {
  if (exploredNode == nullptr) return 0;
  return 1 + std::max(height(exploredNode->left), height(exploredNode->right));
}

bool BinaryTree::exist(const long data) const {
  return search_node(root, data) != nullptr;
}

Node *BinaryTree::search_node(Node *exploredNode, const long data) const {
  if (exploredNode == nullptr || exploredNode->data == data) return exploredNode;
  return search_node((exploredNode->data < data ? exploredNode->right : exploredNode->left), data);
}

Node *BinaryTree::search_parent_node(Node *exploredNode, const long data) const {
  if (exploredNode == nullptr)
    return nullptr;

  if ((exploredNode->left && exploredNode->left->data == data) || (exploredNode->right && exploredNode->right->data == data))
    return exploredNode;

  return search_parent_node((exploredNode->data < data ? exploredNode->right : exploredNode->left), data);
}

void BinaryTree::remove(const long data) {
  Node *parentNode = search_parent_node(root, data);
  Node *nodeToRemove = search_node(root, data);

  if (nodeToRemove == nullptr)
    return;

  if (nodeToRemove->left && nodeToRemove->right) {
    Node *pointer = nodeToRemove->left;
    while (pointer->right != nullptr)
      pointer = pointer->right;
    pointer->right = nodeToRemove->right;
  }

  if (nodeToRemove == root)
    root = nodeToRemove->left;
  else if (parentNode->left == nodeToRemove)
    parentNode->left = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;
  else
    parentNode->right = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;

  delete nodeToRemove;
  treeSize--;
}

void BinaryTree::clear() {
  clear(root);
  root = nullptr;
  treeSize = 0;
}

void BinaryTree::clear(Node *&root) {
  if (root == nullptr) return;
  clear(root->left);
  delete root;
  clear(root->right);
}

long BinaryTree::get_root() const {
  assert(treeSize != 0);
  return root->data;
}

#include "../sources/BinaryTree.cpp"