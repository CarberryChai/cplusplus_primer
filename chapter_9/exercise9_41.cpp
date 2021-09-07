//
// Created by 柴长林 on 2021/3/22.
//
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<char> vc;
  vc.reserve(10);
  for (int i = 0; i < 10; ++i) {
    vc.push_back('c');
  }
  string s(vc.cbegin(), vc.cend());
  std::cout << s << std::endl;
  std::cout << s.assign("hello").replace(0, 1, "H").append(" world")
            << std::endl;
}