#include <cassert>
#include "../headers/BinaryTree.hpp"

template<typename T>
BinaryTree<T>::BinaryTree(int (*comp)(T, T)) {
  root = nullptr;
  tree_size = 0;
  compare = comp;
}

template<typename T>
size_t BinaryTree<T>::size() const {
  return tree_size;
}

template<typename T>
void BinaryTree<T>::insert(Node<T>* &node, const T data) {
  if (node == nullptr) {
    node = new Node<T>(data);
    tree_size++;
  } else {
    int comp_value = compare(data, node->data);
    if (comp_value == -1) insert(node->left, data);
    if (comp_value ==  1) insert(node->right, data);
  }
}

template<typename T>
void BinaryTree<T>::insert(const T data) {
  insert(root, data);
}

template<typename T>
Node<T>* BinaryTree<T>::search_parent_node(Node<T>* node, const T data) {
  if (node == nullptr || compare(data, node->data) == 0) return node;
  if (compare(data, node->data) == -1) {
    return search_node(node->left, data);
  } else {
    return search_node(node->right, data);
  }
}

template<typename T>
Node<T>* get_not_null(Node<T>* node1, Node<T>* node2) {
  return node1 ? node1 : node2;
}

template<typename T>
Node<T>*& get_min_node(Node<T>* node) {
  if (node == nullptr) return node;
  Node<T>* traversing_node = node;
  while (traversing_node->left) {
    traversing_node = traversing_node->left;
  } 
  return traversing_node;
}

template<typename T>
void BinaryTree<T>::remove(const T data) {
  Node<T>* node = search_node(root, data);
  if (node == nullptr) return;
  Node<T>* left_branch = node->left;
  Node<T>* right_branch = node->right;
  if (left_branch == nullptr || right_branch == nullptr) {
    node = get_not_null(left_branch, right_branch);
    return;
  }
  node = right_branch;
  Node<T>* min_node = get_min_node(right_branch);
  min_node->left = left_branch;
}