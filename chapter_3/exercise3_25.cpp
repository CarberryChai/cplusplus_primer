//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vec(11, 0);
  unsigned grade;
  auto it = vec.begin();
  while (std::cin >> grade) {
    if (grade <= 100) {
      *(it + grade / 10) += 1;
    }
  }
  for (auto i : vec) std::cout << i << " ";
}