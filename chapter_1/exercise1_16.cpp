//
// Created by 柴长林 on 2021/2/6.
//
#include <iostream>
int main() {
  int sum = 0;
  std::cout << "Please enter your number: " << std::endl;
  std::cout << "tips: type command + d to terminate the input" << std::endl;
  for (int num = 0; std::cin >> num;) sum += num;
  std::cout << sum << std::endl;
}