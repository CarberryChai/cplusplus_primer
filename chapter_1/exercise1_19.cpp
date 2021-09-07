//
// Created by 柴长林 on 2021/2/7.
//
#include <iostream>

void printNums(int low, int high) {
  while (high >= low) std::cout << high-- << std::endl;
}

int main() {
  int first = 0, second = 0;
  std::cout << "Please enter your first number: " << std::endl;
  if (std::cin >> first) {
    while (std::cin >> second) {
      if (first >= second) {
        std::cout << "the last number must be greater than the first number"
                  << std::endl;
        continue;
      } else
        break;
    }
    printNums(first, second);
  }
}