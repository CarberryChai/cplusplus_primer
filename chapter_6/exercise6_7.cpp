//
// Created by 柴长林 on 2021/2/24.
//
#include <iostream>
size_t count_calls() {
  static size_t ctr;
  return ctr++;
}
int main() {
  for (int i = 0; i < 10; ++i) {
    std::cout << count_calls() << " ";
  }
}