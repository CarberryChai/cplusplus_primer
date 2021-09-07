//
// Created by 柴长林 on 2021/2/7.
//
#include <iostream>

int main() {
  int curVal = 0, value = 0;
  if (std::cin >> curVal) {
    int inc = 1;
    while (std::cin >> value) {
      if (value == curVal)
        inc++;
      else {
        std::cout << curVal << " 重复了：" << inc << " 次。" << std::endl;
        curVal = value;
        inc = 1;
      }
    }
    std::cout << curVal << " 重复了：" << inc << " 次。" << std::endl;
  }
}