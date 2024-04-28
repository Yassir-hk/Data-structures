#include "../headers/ListStack.hpp"

template<typename T>
void ListStack<T>::push(const T data) {
  container.push_front(data);
}

template<typename T>
void ListStack<T>::pop() {
  container.pop_front();
}

template<typename T>
size_t ListStack<T>::size() const {
  return container.size();
}

template<typename T>
bool ListStack<T>::is_empty() const {
  return size() == 0;
}

template<typename T>
T& ListStack<T>::top() {
  return container.front();
}

template<typename T>
void ListStack<T>::print() const {
  container.print();
}