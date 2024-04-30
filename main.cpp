#include <iostream>
#include "headers/ArrayQueue.hpp"

using namespace std;

int main() {
  ArrayQueue<int, 5> queue;
  for (int i = 0; i < 5; ++i) {
    cout << "Queue is empty: " << queue.is_empty() << endl;
    cout << "Queue is full: " << queue.is_full() << endl;
    queue.push(i);
    cout << queue << endl;
  }

  for (int i = 0; i < 5; ++i) {
    cout << "Queue is empty: " << queue.is_empty() << endl;
    cout << "Queue is full: " << queue.is_full() << endl;
    queue.pop();
    cout << queue << endl;
  }
  return 0;
}
