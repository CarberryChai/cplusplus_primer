//
// Created by 柴长林 on 2021/2/25.
//
#include <iostream>

int integer_max(int a, const int *b) { return a > *b ? a : *b; }

int main() {
  std::cout << "Please enter two integers: " << std::endl;
  int x, y;
  if (std::cin >> x >> y) {
    int larger = integer_max(x, &y);
    std::cout << "The larger integer is " << larger << std::endl;
  }
}