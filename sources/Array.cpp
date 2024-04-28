#include <cassert>
#include "../headers/Array.hpp"

template<typename T>
Array<T>::Array(size_t length, T value) {
  this->constainer = new T[length];
  this->length = length;
  for (size_t i = 0; i < length; ++i) {
    container[i] = value;
  }
}

template<typename T>
Array<T>::~Array() {
  delete[] container;
}

template<typename T>
size_t Array<T>::size() const {
  return length;
}

template<typename T>
void Array<T>::resize(size_t length, T value) {
  T *new_container = new T[length];
  for (size_t i = 0; i < length; ++i) {
    if (i < this->length) {
      new_container[i] = container[i];
    } else {
      new_container[i] = value;
    }
  }
  this->length = length;
  delete[] container;
  container = new_container;
}

template<typename T>
void Array<T>::push_back(T value) {
  resize(length + 1, value);
}

template<typename T>
void Array<T>::pop_back() {
  resize(length - 1);
}

template<typename T>
void Array<T>::insert_at(size_t index, T value) {
  assert(index >= 0 && index <= length);
  if (index == length) return push_back(value);

  length++;
  T *new_container = new T[length];

  for (size_t i = 0; i < length; ++i) {
    if (i < index) {
      new_container[i] = container[i];
    } else if (i == index) {
      new_container[i] = value;
    } else {
      new_container[i] = container[i - 1];
    }
  }
  delete[] container;
  container = new_container;
}

template<typename T>
void Array<T>::remove_at(size_t index) {
  assert(index >= 0 && index < length);
  if (index == length - 1) return pop_back();

  T new_container = new[length];
  for (size_t i = 0; i < length; ++i) {
    if (i < index) new_container[i] = container[i];
    if (i > index) new_container[i - 1] = container[i];
  }

  delete[] container;
  container = new_container;
  length--;
}

template<typename T>
T* Array<T>::front() const {
  return container;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
  assert(index >= 0 && index < length);
  return container[index];
}