#include <iostream>
#include "includes/HashTable.hpp"

int main()
{
  // Create a hash table with capacity 10
  HashTable ht(10);

  // Insert some key-value pairs
  ht.insert(42, 100);
  ht.insert(7, 200);
  ht.insert(32, 300);
  ht.insert(12, 400);
  ht.insert(99, 500);

  // Test size() function
  std::cout << "Number of elements in the hash table: " << ht.size() << std::endl;

  // Test get() function
  int value = ht.get(7);
  if (value != -1)
    std::cout << "Value for key 7: " << value << std::endl;
  else
    std::cout << "Key 7 not found." << std::endl;

  // Test find() function
  Node<PAIR> *node = ht.find(32);
  if (node)
    std::cout << "Found key 32: " << node->data.second << std::endl;
  else
    std::cout << "Key 32 not found." << std::endl;

  // Test remove() function
  if (ht.remove(42))
    std::cout << "Key 42 removed successfully." << std::endl;
  else
    std::cout << "Key 42 not found for removal." << std::endl;

  // Test non-existing key removal
  if (ht.remove(100))
    std::cout << "Key 100 removed successfully." << std::endl;
  else
    std::cout << "Key 100 not found for removal." << std::endl;

  // Test non-existing key retrieval
  if (ht.get(123) != -1)
    std::cout << "Value for key 123: " << value << std::endl;
  else
    std::cout << "Key 123 not found." << std::endl;

  ht.display();

  return 0;
}
