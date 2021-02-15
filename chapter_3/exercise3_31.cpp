//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>

int main() {
  int arr[10];
  for (int i = 0; i < 10; ++i) arr[i] = i;
  for (auto x : arr) std::cout << x << " ";
}