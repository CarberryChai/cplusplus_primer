//
// Created by 柴长林 on 2021/4/4.
//
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 5, 6, 5};
  auto n = std::count(vec.begin(), vec.end(), 5);
  std::cout << n << std::endl;

  std::list<std::string> lst{"hello", "world", "hello", "carberry"};
  auto i = std::count(lst.begin(), lst.end(), "hello");
  std::cout << i << std::endl;
}