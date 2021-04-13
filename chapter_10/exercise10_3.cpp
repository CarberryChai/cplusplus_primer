//
// Created by 柴长林 on 2021/4/13.
//
#include <iostream>
#include <numeric>
#include <vector>

using std::vector;

int main() {
  int x;
  vector<int> ivec;
  while (std::cin >> x) ivec.push_back(x);
  int sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
  std::cout << sum << std::endl;
}