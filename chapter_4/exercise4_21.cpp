//
// Created by 柴长林 on 2021/2/18.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vec;
  int val;
  while (std::cin >> val) vec.push_back(val);
  for (auto &x : vec) {
    if (x % 2) x *= x;
  }
  for (const auto x : vec) std::cout << x << " ";
}