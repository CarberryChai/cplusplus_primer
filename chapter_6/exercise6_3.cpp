//
// Created by 柴长林 on 2021/2/24.
//
#include <iostream>
int fact(int x) {
  if (x <= 1) return 1;
  return x * fact(x - 1);
}
int main() {
  std::cout << fact(5) << std::endl;
  std::cout << fact(-100) << std::endl;
  std::cout << fact(10) << std::endl;
}