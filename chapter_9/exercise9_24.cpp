//
// Created by 柴长林 on 2021/3/13.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> v;
  std::cout << v.at(0) << std::endl;
  std::cout << v[0] << std::endl;
  std::cout << v.front() << std::endl;
  std::cout << *v.begin() << std::endl;
}