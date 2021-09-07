//
// Created by 柴长林 on 2021/3/12.
//
#include <list>
#include <iostream>

using std::list;
using std::string;

int main() {
  string s;
  list<string> l;
  while (std::cin >> s) l.push_back(s);
  for (auto it = l.cbegin(); it != l.cend(); ++it) {
    std::cout << *it << std::endl;
  }
}