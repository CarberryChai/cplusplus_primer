//
// Created by 柴长林 on 2021/3/19.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vec;
  int i;
  while (std::cin >> i) vec.push_back(i);
  std::cout << "size: " << vec.size() << "; capacity: " << vec.capacity()
            << std::endl;
  while (vec.size() != vec.capacity()) vec.push_back(42);
  std::cout << "size: " << vec.size() << "; capacity: " << vec.capacity()
            << std::endl;
  vec.push_back(100);
  std::cout << "size: " << vec.size() << "; capacity: " << vec.capacity()
            << std::endl;
  vec.shrink_to_fit();
  std::cout << "size: " << vec.size() << "; capacity: " << vec.capacity()
            << std::endl;
}