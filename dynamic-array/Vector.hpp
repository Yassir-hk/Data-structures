#pragma once


/*
 * Implementation of dynamic array
 */

template <class T>
class Vector
{
    T *buffer;
    size_t _size;
public:
    Vector(const size_t, const T);
    ~Vector();
    size_t size() const;
    T& operator[](const size_t) const;
    void resize(const size_t, const T);
    void push_back(const T);
    T pop_back();
};
