//
// Created by 柴长林 on 2021/4/14.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> ivec{1, 3, 4, 5, 6, 7};
  std::fill_n(ivec.begin(), ivec.size(), 0);
  for (const auto item : ivec) {
    std::cout << item << " ";
  }
  vector<int> vec;
  vec.reserve(10);
  std::fill_n(std::back_inserter(vec), 10, 42);
  for (const auto item : vec) {
    std::cout << item << " ";
  }
}