//
// Created by 柴长林 on 2021/4/16.
//
#include <iostream>

int main() {
  auto sum = [](int a, int b) {
    return a + b;
  };
  std::cout << "sum = " << sum(2, 3) << std::endl;
}