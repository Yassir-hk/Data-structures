#pragma once
#include <ostream>
#include <cstddef>
#include <functional>
#include "DoublyLinkedList.hpp"

template <typename K, typename V>
class Pair {
public:
  K first;
  V second;
  Pair(K f, V s): first(f), second(s) {}
  friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
  }
};

template<typename K, typename V>
class HashTable {
private:
  DoublyLinkedList<Pair<K, V>> **container;
  std::hash<K> hasher;
  size_t hashtable_size;
  size_t capacity;

public:
  HashTable(const size_t n = 1e5);
  ~HashTable();
  size_t size() const;
  Node<Pair<K, V>> *find(const K) const;
  V get(const K) const;
  bool insert(const K, const V);
  bool remove(const K);
  void print() const;
};

#include "../sources/HashTable.cpp"