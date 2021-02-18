//
// Created by 柴长林 on 2021/2/16.
//
#include <iostream>
#include <vector>
int main() {
  std::cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << std::endl;
  int i = 0;
  (++i)++;
  std::cout << i << std::endl;

  std::vector<std::string> vec{"hello", "world", "carberry", ""};
  for (auto it = vec.begin(); it != vec.end();) {
    if (!it++->empty()) std::cout << *it << " ";
  }
}