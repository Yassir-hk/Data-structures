#include <cassert>
#include <iostream>
#include "../headers/HashTable.hpp"

template<typename K, typename V>
HashTable<K, V>::HashTable(const size_t n) {
  hashtable_size = 0;
  container = new DoublyLinkedList<Pair<K, V>>*[n];
  capacity = n;
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() {
  for(size_t i = 0; i < capacity; ++i) {
    if (container[i] != nullptr) container[i]->clear();
  }
}

template<typename K, typename V>
size_t HashTable<K, V>::size() const {
  return hashtable_size;
}

template<typename K, typename V>
V HashTable<K, V>::get(const K key) const {
  const Node<Pair<K, V>> *node = find(key);
  return node != nullptr ? node->data.second:-1;
}

template<typename K, typename V>
Node<Pair<K, V>>* HashTable<K, V>::find(const K key) const {
  const size_t idx = hasher(key) % capacity;

  if (container[idx] == nullptr || container[idx]->size() == 0) return nullptr;
  Node<Pair<K, V>> *it = container[idx]->get_head();

  while (it != nullptr) {
    if (it->data.first == key) return it;
    it = it->next;
  }

  return nullptr;
}

template<typename K, typename V>
bool HashTable<K, V>::insert(const K key, const V value) {
  if (find(key) != nullptr) return false;
  const size_t idx = hasher(key) % capacity;
  if (container[idx] == nullptr) container[idx] = new DoublyLinkedList<Pair<K, V>>();
  container[idx]->push_front({key, value});
  hashtable_size++;
  return true;
}

template<typename K, typename V>
bool HashTable<K, V>::remove(const K key) {
  const size_t idx = hasher(key) % capacity;
  Node<Pair<K, V>> *node = find(key);
  if(node == nullptr) return false;
  container[idx]->remove_node(node);
  hashtable_size--;
  return true;
}

template<typename K, typename V>
void HashTable<K, V>::print() const {
  for (size_t i = 0; i < capacity; ++i) {
    if (container[i] == nullptr) {
      std::cout << "nullptr\n";
      continue;
    }
    std::cout << *container[i] << "\n";
  }
}