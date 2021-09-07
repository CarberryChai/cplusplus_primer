//
// Created by 柴长林 on 2021/2/13.
//
#include <iostream>

int main() {
  const int i = 42;
  auto j = i;                  // j is int
  const auto &k = i;           // k is const int&
  auto *p = &i;                // p is const int*
  const auto j2 = i, &k2 = i;  // j2 is const int; k2 is const int&
  std::cout << j << std::endl;
  std::cout << k << std::endl;
  std::cout << p << std::endl;
  std::cout << j2 << std::endl;
  std::cout << k2 << std::endl;
}