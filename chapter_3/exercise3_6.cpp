//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>

int main() {
  std::string str;
  while (std::cin >> str) {
    for (auto &c : str) c = 'X';
    std::cout << str << std::endl;
  }
}