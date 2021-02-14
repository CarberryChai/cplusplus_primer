//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>
int main() {
  std::string str;
  while (std::cin >> str) {
    for (decltype(str.size()) index = 0; index != str.size(); ++index)
      str[index] = 'X';
    std::cout << str << std::endl;
  }
}