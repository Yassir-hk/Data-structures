#pragma once

#include <iostream>
#include <stdexcept>


// Node structure represent nodes of the binary tree
struct Node
{
  long data;
  Node *left;
  Node *right;
  Node(long d = 0, Node *l = nullptr, Node *r = nullptr) : data(d), left(l), right(r) {}
};

// Binary tree class
class BinaryTree
{
private:
  Node *root;       // Pointer to the root node of the binary tree
  size_t treeSize;  // Number of nodes in the binary tree

public:
  BinaryTree() : treeSize(0), root(nullptr) {}
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


// Destructor
BinaryTree::~BinaryTree()
{
  clear();
}

// Return the number of nodes on the tree
size_t BinaryTree::size() const
{
  return treeSize;
}

// Print all elements of the tree
void BinaryTree::display() const
{
  display(root);
}

void BinaryTree::display(Node *exploredNode) const
{
  if (exploredNode == nullptr)
    return;

  display(exploredNode->left);
  std::cout << " " << exploredNode->data;
  display(exploredNode->right);
}

// Count the number of levels (height) of the tree
size_t BinaryTree::height() const
{
  return height(root);
}

size_t BinaryTree::height(Node *exploredNode) const
{
  if (exploredNode == nullptr)
    return 0;

  return 1 + std::max(height(exploredNode->left), height(exploredNode->right));
}

// Check if certain element exist in the tree
bool BinaryTree::exist(const long data) const
{
  return search_node(root, data) != nullptr;
}

// Insert element to the tree
void BinaryTree::insert(const long data)
{
  insert(root, data);
  treeSize++;
}

void BinaryTree::insert(Node *&exploredNode, const long data)
{
  if (exploredNode == nullptr)
    exploredNode = new Node(data);
  else if (data < exploredNode->data)
    insert(exploredNode->left, data);
  else if (data > exploredNode->data)
    insert(exploredNode->right, data);
}

// Search for specific node
Node *BinaryTree::search_node(Node *exploredNode, const long data) const
{
  if (exploredNode == nullptr || exploredNode->data == data)
    return exploredNode;

  return search_node((exploredNode->data < data ? exploredNode->right : exploredNode->left), data);
}

// Search for the parent of a node
Node *BinaryTree::search_parent_node(Node *exploredNode, const long data) const
{
  if (exploredNode == nullptr)
    return nullptr;

  if ((exploredNode->left && exploredNode->left->data == data) || (exploredNode->right && exploredNode->right->data == data))
    return exploredNode;

  return search_parent_node((exploredNode->data < data ? exploredNode->right : exploredNode->left), data);
}

// Remove specific node
void BinaryTree::remove(const long data)
{
  Node *parentNode = search_parent_node(root, data);
  Node *nodeToRemove = search_node(root, data);

  if (nodeToRemove == nullptr)
    return;

  if (nodeToRemove->left && nodeToRemove->right)
  {
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

// Delete all nodes of the tree
void BinaryTree::clear()
{
  clear(root);
  root = nullptr;
  treeSize = 0;
}

void BinaryTree::clear(Node *&root)
{
  if (root == nullptr)
    return;

  clear(root->left);
  delete root;
  clear(root->right);
}

//  Return the root node
long BinaryTree::getRoot() const
{
  if (treeSize == 0)
    throw std::runtime_error("Tree is empty");

  return root->data;
}