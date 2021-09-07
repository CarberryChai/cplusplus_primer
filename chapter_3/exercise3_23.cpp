//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vec;
  vec.reserve(10);
  for (int i = 0; i < 10; i++) vec.push_back(i + 1);
  for (auto it = vec.begin(); it != vec.end(); ++it) *it = *it * *it;
  for (auto x : vec) std::cout << x << " ";
}