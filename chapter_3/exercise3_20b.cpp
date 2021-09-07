//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>
#include <vector>
using std::vector;
int main() {
  vector<int> ivec;
  int x;
  while (std::cin >> x) ivec.push_back(x);
  for (vector<int>::size_type i = 0, j = ivec.size() - 1; i < j; ++i, --j) {
    std::cout << ivec[i] + ivec[j] << std::endl;
  }
}