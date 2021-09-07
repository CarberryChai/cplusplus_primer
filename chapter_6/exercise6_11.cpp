//
// Created by 柴长林 on 2021/2/25.
//
#include <iostream>

void reset(int &x) { x = 0; }

int main() {
  int i = 42;
  std::cout << i << std::endl;
  reset(i);
  std::cout << i << std::endl;
}