#pragma once

#include <random>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.hpp"

typedef std::pair<int, int> PAIR;
typedef DoublyLinkedList<PAIR> DDList;
typedef std::vector<DDList> Buffer;

// The Hasher class represents the necessary element to achieve good hashing and avoid collision
class Hasher
{
private:
  size_t a, b, p;
public:
  Hasher(size_t);
  size_t hash(const int, const size_t) const;
  size_t get_random_number(const size_t, const size_t) const;
  bool is_prime(size_t) const;
};

// The HashTable class represents a hash table with chaining to handle collisions.
class HashTable
{
private:
  Buffer container;       // Array of DoublyLinkedList to store key-value pairs
  size_t hashTableSize; // Current number of elements in the hash table
  Hasher *hasher;        // Hasher object for hashing operations

public:
  HashTable(const size_t);
  ~HashTable();
  size_t size() const;
  int get(const size_t) const;
  Node<PAIR> *find(const int) const;
  bool insert(const int, const int);
  bool remove(const int);
  void print() const;
};


// Constructor of the hasher obeject
Hasher::Hasher(size_t capacity)
{
  p = capacity + 1;
  while (!is_prime(p))
    ++p;
  
  a = get_random_number(0, p);
  b = get_random_number(1, p);
}

// The hash function that generate a good distributions of hashed key to improve the time complexity
// The probability of two keys to collides using this function is 1/capacity of the container
size_t Hasher::hash(const int key, const size_t capacity) const
{
  return (size_t) ((a * key + b) % p) % capacity;
}

// Function that generate a random number in the interval [s, f]
size_t Hasher::get_random_number(const size_t s, const size_t f) const
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> dist(s, f);
  return dist(gen);
}

// Function that check if n is prime number or not
bool Hasher::is_prime(size_t n) const
{
  if (n == 0 || n == 1)
    return false;

  for (size_t i = 2; i <= n / 2; ++i)
    if (n % i == 0)
      return false;

  return true;
}

// Constructor of the HashTable object
HashTable::HashTable(size_t capacity)
{
  hashTableSize = 0;
  container.resize(capacity);
  hasher = new Hasher(container.size());
}

// Destructor
HashTable::~HashTable()
{
  for(size_t i = 0; i < container.size(); ++i)
    container[i].clear();
  delete hasher;
}

// Return the number of element in the hash table
size_t HashTable::size() const
{
  return hashTableSize;
}

int HashTable::get(const size_t key) const
{
  const Node<PAIR> *Node = find(key);
  return Node != nullptr ? Node->data.second : -1;
}

// Search and return the value corresponding to the given key
Node<PAIR> *HashTable::find(const int key) const
{
  const size_t idx = hasher->hash(key, container.size());

  if (container[idx].size() == 0)
    return nullptr;

  Node<PAIR> *it = container[idx].front();

  while (it)
  {
    if (it->data.first == key)
      return it;
    it = it->next;
  }

  return nullptr;
}

// Insert the given pair(key, value)
bool HashTable::insert(const int key, const int value)
{
  if (find(key) != nullptr)
    return false;

  const size_t idx = hasher->hash(key, container.size());
  container[idx].push_front(std::make_pair(key, value));
  hashTableSize++;

  // Keep the hash table operations in constant time
  if (hashTableSize == container.size())
    container.resize(container.size() + container.size() / 2);

  return true;
}

// Remove the element of the corresponding key
bool HashTable::remove(const int key)
{
  const size_t idx = hasher->hash(key, container.size());
  Node<PAIR> *it = find(key);

  if(it == nullptr)
    return false;

  container[idx].remove_node(it);
  hashTableSize--;

  return true;
}

void HashTable::print() const
{
  for (const DDList &l : container)
  {
    if (l.size())
    {
      Node<PAIR> *it = l.front();
      while (it)
      {
        std::cout << it->data.second << " ";
        it = it->next;
      }
    }
  }
  std::cout << "\n";
}