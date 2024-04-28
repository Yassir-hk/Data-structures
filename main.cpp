#include "headers/singly_linked_list.hpp"

const int N = 20;

int main() {
  SinglyLinkedList<int> test_list;
  for (int i = 0; i < N; ++i) {
    if (i & 1) test_list.push_back(i);
    else test_list.push_front(i);
  }
  test_list.print();
  test_list.insert_at(0, 654);
  test_list.insert_at(5, 888);
  test_list.print();
  while (test_list.size()) {
    if (test_list.size() & 1) test_list.pop_back();
    else test_list.pop_front();
    test_list.print();
  }
}