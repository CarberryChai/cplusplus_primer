//
// Created by 柴长林 on 2021/3/12.
//
#include <deque>
#include <iostream>

using std::deque;
using std::string;

int main() {
  string s;
  deque<string> d;
  while (std::cin >> s) d.push_back(s);
  for (auto it = d.cbegin(); it != d.cend(); ++it) {
    std::cout << *it << std::endl;
  }
}