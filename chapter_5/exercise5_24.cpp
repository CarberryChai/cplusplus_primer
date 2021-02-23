//
// Created by 柴长林 on 2021/2/23.
//
#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  if (y == 0) throw std::runtime_error("the division must not be zero");
  std::cout << x / y << std::endl;
}