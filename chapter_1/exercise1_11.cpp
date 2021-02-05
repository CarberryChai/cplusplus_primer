//
// Created by 柴长林 on 2021/2/5.
//
#include <iostream>
void printNums(int low, int high) {
  if (low >= high) {
    printNums(high, low);
    return;
  }
  while (high >= low) std::cout << high-- << std::endl;
}
int main() {
  std::cout << "Please enter two integers: " << std::endl;
  int x = 0, y = 0;
  std::cin >> x >> y;
  printNums(x, y);
}