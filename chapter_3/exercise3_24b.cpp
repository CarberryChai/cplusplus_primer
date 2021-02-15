//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vec;
  int x;
  while (std::cin >> x) vec.push_back(x);

  for (auto it1 = vec.begin(), it2 = vec.end() - 1; it1 < it2; ++it1, --it2) {
    std::cout << *it1 + *it2 << " ";
  }
}