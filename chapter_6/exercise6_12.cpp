//
// Created by 柴长林 on 2021/2/25.
//
#include <iostream>
void mySwap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
int main() {
  std::cout << "Please enter two numbers to swap: " << std::endl;
  int x, y;
  if (std::cin >> x >> y) {
    std::cout << "the first number is " << x << std::endl;
    std::cout << "the second number is " << y << std::endl;
    mySwap(x, y);
    std::cout << "after the swap" << std::endl;
    std::cout << "the first number is " << x << std::endl;
    std::cout << "the second number is " << y << std::endl;
  }
}