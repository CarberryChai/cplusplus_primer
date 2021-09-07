//
// Created by 柴长林 on 2021/9/7.
//
#include <iostream>
#include <vector>

using std::vector;
std::shared_ptr<vector<int>> getints() { return std::make_shared<vector<int>>(); }
void read(const std::shared_ptr<vector<int>>& vec) {
  int x;
  while (std::cin >> x) vec->push_back(x);
}
void print(const std::shared_ptr<vector<int>>& vec) {
  for (auto i : *vec) std::cout << i << " ";
}
int main() {
  auto p = getints();
  read(p);
  print(p);
}