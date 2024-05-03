#include <cassert>
#include "../headers/Array.hpp"

template<typename T>
Array<T>::Array(size_t array_size, T value) {
  this->constainer = new T[array_size];
  this->array_size = array_size;
  for (size_t i = 0; i < array_size; ++i) {
    container[i] = value;
  }
}

template<typename T>
Array<T>::~Array() {
  delete[] container;
}

template<typename T>
size_t Array<T>::size() const {
  return array_size;
}

template<typename T>
void Array<T>::resize(size_t array_size, T value) {
  T *new_container = new T[array_size];
  for (size_t i = 0; i < array_size; ++i) {
    if (i < this->array_size) {
      new_container[i] = container[i];
    } else {
      new_container[i] = value;
    }
  }
  this->array_size = array_size;
  delete[] container;
  container = new_container;
}

template<typename T>
void Array<T>::push_back(T value) {
  resize(array_size + 1, value);
}

template<typename T>
void Array<T>::pop_back() {
  resize(array_size - 1);
}

template<typename T>
void Array<T>::insert_at(size_t idx, T value) {
  assert(idx >= 0 && idx <= array_size);
  if (idx == array_size) return push_back(value);

  array_size++;
  T *new_container = new T[array_size];

  for (size_t i = 0; i < array_size; ++i) {
    if (i < idx) {
      new_container[i] = container[i];
    } else if (i == idx) {
      new_container[i] = value;
    } else {
      new_container[i] = container[i - 1];
    }
  }
  delete[] container;
  container = new_container;
}

template<typename T>
void Array<T>::remove_at(size_t idx) {
  assert(idx >= 0 && idx < array_size);
  if (idx == array_size - 1) return pop_back();

  T new_container = new[array_size];
  for (size_t i = 0; i < array_size; ++i) {
    if (i < idx) new_container[i] = container[i];
    if (i > idx) new_container[i - 1] = container[i];
  }

  delete[] container;
  container = new_container;
  array_size--;
}

template<typename T>
T* Array<T>::front() const {
  return container;
}

template<typename T>
T& Array<T>::operator[](size_t idx) {
  assert(idx >= 0 && idx < array_size);
  return container[idx];
}