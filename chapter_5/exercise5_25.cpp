//
// Created by 柴长林 on 2021/2/23.
//
#include <iostream>

int main() {
  int x, y;
  while (std::cin >> x >> y) {
    try {
      if (y == 0) throw std::runtime_error("the division must not be zero");
      std::cout << x / y << std::endl;
    } catch (std::runtime_error &err) {
      std::cout << err.what() << "\nTry Again? Enter y or n" << std::endl;
      char c;
      std::cin >> c;
      if (!std::cin || c == 'n') break;
    }
  }
}