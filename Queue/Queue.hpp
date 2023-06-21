#pragma once

/*
 * Array implementation of queue
 */

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