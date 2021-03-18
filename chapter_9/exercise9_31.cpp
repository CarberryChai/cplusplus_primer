//
// Created by 柴长林 on 2021/3/18.
//
#include <iostream>
#include <list>

using std::list;

int main() {
  list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it = l.begin();
  while (it != l.end()) {
    if (*it % 2) {
      l.insert(it, *it++);
    } else {
      it = l.erase(it);
    }
  }
  for (auto item : l) {
    std::cout << item << " ";
  }
}