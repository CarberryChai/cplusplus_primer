//
// Created by 柴长林 on 2021/3/18.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto begin = vi.begin();
  while (begin != vi.end()) {
    ++begin;
    /*begin = */ vi.insert(begin, 42);
    ++begin;
  }
  for (auto item : vi) {
    std::cout << item << " ";
  }
}