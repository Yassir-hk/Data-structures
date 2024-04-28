#pragma once
#include <iostream>
#include <stdexcept>

struct Node {
  long data;
  Node *left;
  Node *right;
  Node(long d = 0, Node *l = nullptr, Node *r = nullptr) : data(d), left(l), right(r) {}
};

class BinaryTree {
private:
  Node *root;
  size_t treeSize;

public:
  BinaryTree() : treeSize(0), root(nullptr) {}
  ~BinaryTree();
  size_t size() const;
  size_t height() const;
  bool exist(const long) const;
  void print() const;
  void insert(const long);
  void remove(const long);
  void clear();
  long getRoot() const;

private:
  void print(Node *) const;
  void insert(Node *&, const long);
  size_t height(Node *) const;
  Node *search_node(Node *, const long) const;
  Node *search_parent_node(Node *, const long) const;
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

void BinaryTree::insert(const long data) {
  insert(root, data);
  treeSize++;
}

void BinaryTree::insert(Node *&exploredNode, const long data) {
  if (exploredNode == nullptr)
    exploredNode = new Node(data);
  else if (data < exploredNode->data)
    insert(exploredNode->left, data);
  else if (data > exploredNode->data)
    insert(exploredNode->right, data);
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

long BinaryTree::getRoot() const {
  assert(treeSize != 0);
  return root->data;
}