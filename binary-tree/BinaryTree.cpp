#include <iostream>
#include <stdexcept>
#include "BinaryTree.hpp"
using namespace std;


// Destructor
BinaryTree::~BinaryTree() {
    clear();
}

/*
 * Return the number of nodes on the tree
 */

size_t BinaryTree::size() const {
    return _size;
}

/*
 * Print all elements of the tree
 */

void BinaryTree::display() const {
    display(root);
}

void BinaryTree::display(Node *exploredNode) const
{
    if (exploredNode == nullptr) {
        return;
    }

    display(exploredNode->left);
    cout << " " << exploredNode->data;
    display(exploredNode->right);
}

/*
 * Count the number of levels (height) of the tree
 */

size_t BinaryTree::height() const {
    return height(root);
}

size_t BinaryTree::height(Node *exploredNode) const
{
    if (exploredNode == nullptr) {
        return 0;
    }

    return 1 + max(height(exploredNode->left), height(exploredNode->right));
}

/*
 * Check if certain element exist in the tree
 */

bool BinaryTree::exist(const long data) const {
    return search_node(root, data) != nullptr;
}

/*
 * Insert element to the tree
 */

void BinaryTree::insert(const long data)
{
    insert(root, data);
    _size++;
}

void BinaryTree::insert(Node *&exploredNode, const long data)
{
    if (exploredNode == nullptr) {
        exploredNode = new Node(data);
    }
    else if (data < exploredNode->data) {
        insert(exploredNode->left, data);
    }
    else if (data > exploredNode->data) {
        insert(exploredNode->right, data);
    }
}

/*
 * Search for specific node
 */

Node *BinaryTree::search_node(Node *exploredNode, const long data) const
{
    if (exploredNode == nullptr || exploredNode->data == data) {
        return exploredNode;
    }

    return search_node((exploredNode->data < data ? exploredNode->right : exploredNode->left), data);
}

/*
 * Search for the parent of a node
 */

Node *BinaryTree::search_parent_node(Node *exploredNode, const long data) const
{
    if (exploredNode == nullptr) {
        return nullptr;
    }
    else if ((exploredNode->left && exploredNode->left->data == data)||(exploredNode->right && exploredNode->right->data == data) ) {
        return exploredNode;
    }

    return search_parent_node((exploredNode->data < data ? exploredNode->right : exploredNode->left), data);
}

/*
 * Remove specific node
 */

void BinaryTree::remove(const long data)
{
    Node *parentNode = search_parent_node(root, data);
    Node *nodeToRemove = search_node(root, data);

    if (nodeToRemove == nullptr) {
        return;
    }
    else if (nodeToRemove->left && nodeToRemove->right)
    {
        Node *pointer = nodeToRemove->left;
        while (pointer->right != nullptr) {
            pointer = pointer->right;
        }
        pointer->right = nodeToRemove->right;
    }

    if (nodeToRemove == root) {
        root = nodeToRemove->left;
    }
    else if (parentNode->left == nodeToRemove) {
        parentNode->left = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;
    }
    else {
        parentNode->right = nodeToRemove->left ? nodeToRemove->left : nodeToRemove->right;
    }

    delete nodeToRemove;
    _size--;
}

/*
 * Delete all nodes of the tree
 */

void BinaryTree::clear()
{
    clear(root);
    root = nullptr;
    _size = 0;
}

void BinaryTree::clear(Node *&root)
{
    if (root == nullptr) {
        return;
    }

    clear(root->left);
    delete root;
    clear(root->right);
}

/*
 * Return the root node
 */

long BinaryTree::getRoot() const
{
    if (_size == 0) {
        throw runtime_error("Tree is empty");
    }

    return root->data;
}