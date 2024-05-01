#include <cassert>
#include <iostream>
#include "../headers/BinaryTree.hpp"

template<typename T>
BinaryTree<T>::BinaryTree(int (*comp)(T, T)) {
  root = nullptr;
  tree_size = 0;
  compare = comp;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
  clear();
}

template<typename T>
size_t BinaryTree<T>::size() const {
  return tree_size;
}

template<typename T>
void BinaryTree<T>::insert(Node<T>*& node, const T data) {
  if (node == nullptr) {
    node = new Node<T>(data);
    tree_size++;
  } else {
    int comp_value = compare(data, node->data);
    if (comp_value < 0) insert(node->left, data);
    if (comp_value > 0) insert(node->right, data);
  }
}

template<typename T>
void BinaryTree<T>::insert(const T data) {
  insert(root, data);
}

template<typename T>
bool BinaryTree<T>::exist(Node<T>* node, const T data) const {
  if (node == nullptr) return false;
  int comp_value = compare(data, node->data);
  if (comp_value == 0) return true;
  return comp_value < 0 ? exist(node->left, data) : exist(node->right, data);
}

template<typename T>
bool BinaryTree<T>::exist(const T data) const {
  return exist(root, data);
}

template<typename T>
Node<T>* get_not_null(Node<T>*& node1, Node<T>*& node2) {
  return node1 != nullptr ? node1:node2;
}

template<typename T>
Node<T>* get_min_node(Node<T>* node) {
  if (node == nullptr) return node;
  while (node->left) {
    node = node->left;
  } 
  return node;
}

template<typename T>
void BinaryTree<T>::remove(Node<T>*& node, const T data) {
  if (node == nullptr) return;
  int comp_value = compare(data, node->data);
  if (comp_value < 0) return remove(node->left, data);
  if (comp_value > 0) return remove(node->right, data);

  Node<T>* left_branch = node->left;
  Node<T>* right_branch = node->right;

  delete node;
  if (left_branch && right_branch) {
    node = right_branch;
    Node<T>* min_node = get_min_node(right_branch);
    min_node->left = left_branch;
  } else {
    node = get_not_null(left_branch, right_branch);
  }

  tree_size--;
}

template<typename T>
void BinaryTree<T>::remove(const T data) {
  remove(root, data);
}

template<typename T>
void BinaryTree<T>::inorder_traversal(Node<T>* node) const {
  if (node == nullptr) return;
  inorder_traversal(node->left);
  std::cout << " " << node->data;
  inorder_traversal(node->right);
}

template<typename T>
void BinaryTree<T>::inorder_traversal() const {
  inorder_traversal(root);
}

template<typename T>
void BinaryTree<T>::preorder_traversal(Node<T>* node) const {
  if (node == nullptr) return;
  std::cout << node->data << " ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

template<typename T>
void BinaryTree<T>::preorder_traversal() const {
  preorder_traversal(root);
}

template<typename T>
void BinaryTree<T>::postorder_traversal(Node<T>* node) const {
  if (node == nullptr) return;
  postorder_traversal(node->left);
  postorder_traversal(node->right);
  std::cout << node->data << " ";
}

template<typename T>
void BinaryTree<T>::postorder_traversal() const {
  postorder_traversal(root);
}

template<typename T>
void BinaryTree<T>::clear(Node<T> *root) {
  if (root == nullptr) return;
  clear(root->left);
  delete root;
  clear(root->right);
}

template <typename T>
void BinaryTree<T>::clear() {
  clear(root);
  root = nullptr;
  tree_size = 0;
}

template<typename T>
size_t BinaryTree<T>::height(Node<T>* node) const {
  if (node == nullptr) return 0;
  return 1 + std::max(height(node->left), height(node->right));
}

template<typename T>
size_t BinaryTree<T>::height() const {
  return height(root);
}
