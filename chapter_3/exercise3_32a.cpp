//
// Created by 柴长林 on 2021/2/15.
//
#include <cstddef>
#include <iostream>
int main() {
  int arr1[10], arr2[10];
  for (size_t i = 0; i < 10; ++i) arr1[i] = i;
  for (size_t i = 0; i < 10; ++i) arr2[i] = arr1[i];
  for (auto x : arr2) std::cout << x << " ";
}