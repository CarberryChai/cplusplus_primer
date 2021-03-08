//
// Created by 柴长林 on 2021/3/8.
//
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

int main() {
  vector<int> v1(10, 2);
  list<int> l1(10, 8);
  vector<double> v2(v1.begin(), v1.end());
  vector<double> v3(l1.begin(), l1.end());
  for (auto item : v2) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  for (auto item : v3) {
    std::cout << item << " ";
  }
}