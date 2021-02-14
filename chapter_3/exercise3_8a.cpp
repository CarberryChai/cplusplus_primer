//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>
int main() {
  std::string str;
  while (std::cin >> str) {
    decltype(str.size()) index = 0;
    while (index != str.size()) {
      str[index] = 'X';
      ++index;
    }
    std::cout << str << std::endl;
  }
}