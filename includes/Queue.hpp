#pragma once

#include <iostream>
#include <stdexcept>


// Queue class represent the queue data structure based on array
template <typename T, size_t N>
class Queue
{
private:
  T buffer[N];
  size_t queueHead;
  size_t queueTail;

public:
  Queue(size_t s) : queueHead(0), queueTail(0) {}
  T dequeue();
  void display() const;
  void enqueue(const T &);
  bool is_empty() const;
  bool is_full() const;
  size_t size() const;
  size_t capacity() const;
};


// Check if the queue is empty
template <typename T, size_t N>
bool Queue<T, N>::is_empty() const
{
  return size() == 0;
}

// Check if the queue is full
template <typename T, size_t N>
bool Queue<T, N>::is_full() const
{
  return size() == capacity();
}

// Return the number of elements on the queue
template <typename T, size_t N>
size_t Queue<T, N>::size() const
{
  return queueTail - queueHead;
}

// Return the maximum capacity of the queue
template <typename T, size_t N>
size_t Queue<T, N>::capacity() const
{
  return N;
}

// Insert element to the queue
template <typename T, size_t N>
void Queue<T, N>::enqueue(const T &data)
{
  if (is_full())
    throw std::runtime_error("Queue is full");

  const size_t index = (queueTail < N ? queueTail : queueTail % N);
  buffer[index] = data;
  queueTail++;
}

// Delete element from the queue
template <typename T, size_t N>
T Queue<T, N>::dequeue()
{
  if (is_empty())
    throw std::runtime_error("Queue is empty");

  const size_t index = (queueHead < N ? queueHead : queueHead % N);
  const T data = buffer[index];
  queueHead++;
  return data;
}

// Diplay all element of the queue
template <typename T, size_t N>
void Queue<T, N>::display() const
{
  if (is_empty())
    return;

  for (size_t i = queueHead; i < queueTail; ++i) {
    const size_t index = i < N ? i : i % N;
    cout << " " << buffer[index];
  }
}