#include <cassert>
#include "../headers/ListQueue.hpp"

template<typename T>
size_t ListQueue<T>::size() const {
  return container.size();
}

template<typename T>
bool ListQueue<T>::is_empty() const {
  return size() == 0;
}

template<typename T>
void ListQueue<T>::push(const T data) {
  container.push_back(data);
}

template<typename T>
void ListQueue<T>::pop() {
  container.pop_front();
}

template<typename T>
T& ListQueue<T>::front() const {
  return container.back();
}

template<typename T>
T& ListQueue<T>::back() const {
  return container.front();
}

template<typename T>
void ListQueue<T>::print() const {
  container.print();
}