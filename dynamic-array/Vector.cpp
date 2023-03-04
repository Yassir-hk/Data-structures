#include <iostream>
#include <stdexcept>
#include "Vector.hpp"
using namespace std;

// Initialize the array
template <class T>
Vector<T>::Vector(const size_t len, const T value) : _size(len)
{
    if (_size != 0)
    {
        buffer = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            buffer[i] = value;
        }
    }
}

// Destructor
template <class T>
Vector<T>::~Vector() {
    delete[] buffer;
}

// Return the number of element of the array
template <class T>
size_t Vector<T>::size() const {
    return _size;
}

// Resize the array and fill tha additional space by specific value
template <class T>
void Vector<T>::resize(const size_t len, const T value = 0)
{
    if (len == _size) {
        return;
    }

    T *tmpbuffer = new T[len];
    memcpy(tmpbuffer, buffer, sizeof(T) * _size);

    for (size_t i = _size; i < len; ++i) {
        tmpbuffer[i] = value;
    }
    
    delete[] buffer;
    buffer = tmpbuffer;
    _size = len;
}

// Operator overloading to access the index-th element
template <class T>
T& Vector<T>::operator[](const size_t index) const
{
    if (position >= _size) {
        throw runtime_error("Index out of bound");
    }

    return buffer[position];
}

// Inserting an element to the end of the array
template <class T>
void Vector<T>::push_back(const T value) {
    resize(_size + 1, value);
}

// Deleting the last element of the array
template <class T>
T Vector<T>::pop_back()
{
    if (_size == 0) {
        throw runtime_error("Array is empty");
    }

    T data = buffer[_size - 1];
    resize(--_size);
    return data;
}