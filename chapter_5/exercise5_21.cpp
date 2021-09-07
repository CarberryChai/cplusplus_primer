//
// Created by 柴长林 on 2021/2/23.
//
#include <cctype>
#include <iostream>
using std::string;

int main() {
  string str, current;
  while (std::cin >> current) {
    if (!isupper(current[0])) continue;
    if (str == current) {
      std::cout << "The repeated string is " << current << std::endl;
      break;
    }
    str = current;
  }
  if (std::cin.fail()) std::cout << "no words were repeated" << std::endl;
}