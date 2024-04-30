#include <cassert>
#include "headers/BinaryTree.hpp"

int compare(int a, int b) {
  return a < b ? -1 : a == b ? 0 : 1;
}

int main() {
  BinaryTree<int> tree(compare);
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  assert(tree.size() == 3);

  // Test case for existence check
  assert(tree.exist(5));
  assert(!tree.exist(1));

  // Test case for inorder traversal
  std::cout << "Inorder traversal: ";
  tree.inorder_traversal();
  std::cout << std::endl;  // Print newline after traversal

  // Test case for preorder traversal
  std::cout << "Preorder traversal: ";
  tree.preorder_traversal();
  std::cout << std::endl;  // Print newline after traversal

  // Test case for postorder traversal
  std::cout << "Postorder traversal: ";
  tree.postorder_traversal();
  std::cout << std::endl;  // Print newline after traversal

  // Test case for removal (single child)
  tree.remove(3);
  assert(tree.size() == 2);

  // Test case for removal (no child)
  tree.insert(1);
  tree.remove(1);
  assert(tree.size() == 1);

  // Test case for removal (two children)
  tree.insert(9);
  tree.insert(8);
  tree.remove(5);
  assert(tree.size() == 2);
  assert(tree.exist(5) == false);
  assert(tree.height() == 2);
  std::cout << "All tests passed!" << std::endl;
  return 0;
}
