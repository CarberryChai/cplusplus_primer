//
// Created by 柴长林 on 2021/2/15.
//
#include <cstddef>
#include <iostream>
#include <vector>
using std::vector;

int main() {
  int arr1[10];
  vector<int> arr2(10);
  for (size_t i = 0; i < 10; ++i) arr1[i] = i;
  for (decltype(arr2.size()) index = 0; index < 10; ++index)
    arr2[index] = arr1[index];
  for (auto x : arr2) std::cout << x << " ";

  unsigned scores[11];
  unsigned x;
  while (std::cin >> x) {
    if (x <= 100) ++scores[x / 10];
  }
  for (auto y : scores) std::cout << y << " ";
}