//
// Created by 柴长林 on 2021/2/19.
//
#include <iostream>
int main() {
  int sum = 0, val = 1;
  while (val <= 10) sum += val, ++val;

  std::cout << sum << std::endl;
}