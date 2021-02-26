//
// Created by 柴长林 on 2021/2/26.
//
#include <iostream>
#include <vector>

using std::initializer_list;
using std::vector;

int sum(initializer_list<int> lt) {
  int result = 0;
  for (auto item : lt) result += item;
  return result;
}
int main() { std::cout << sum({1, 2, 3, 4}) << std::endl; }