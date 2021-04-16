//
// Created by 柴长林 on 2021/4/16.
//
#include <iostream>

int main() {
  std::cout << "input an number and addition 1: " << std::endl;
  int i;
  std::cin >> i;
  auto sum = [i](int j) {
    return i+j;
  };
  std::cout << "sum: " << sum(1) << std::endl;
}