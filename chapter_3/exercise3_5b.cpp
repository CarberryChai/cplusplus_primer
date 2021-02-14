//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>
using std::string;
int main() {
  string total, curVal;
  while (std::cin >> curVal) {
    if (!curVal.empty()) total += curVal + " ";
  }
  std::cout << total << std::endl;
}