//
// Created by 柴长林 on 2021/3/10.
//
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

int main() {
  list<const char*> l = {"hello world", "carberry"};
  vector<std::string> v;
  v.assign(l.begin(), l.end());
  for (const auto& item : v) {
    std::cout << item << std::endl;
  }
}