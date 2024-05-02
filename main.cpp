#include <iostream>
#include "headers/HashTable.hpp"

int main() {
  // Create a hash table with string keys and integer values
  HashTable<std::string, int> mp(12);

  // Insert 15 key-value pairs into the hash table
  for (int i = 0; i < 15; ++i) {
    std::string key = "key_" + std::to_string(i);
    int value = i * 10;
    mp.insert(key, value);
  }

  // Print the size of the hash table
  std::cout << "Hash Table Size: " << mp.size() << std::endl;
  mp.print();

  return 0;
}