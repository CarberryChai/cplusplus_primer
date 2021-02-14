//
// Created by 柴长林 on 2021/2/14.
//
#include <cctype>
#include <iostream>
int main() {
  std::string str;
  std::cin >> str;
  for (auto &c : str) {
    if (ispunct(c)) c = 0;
  }
  std::cout << str << std::endl;
}