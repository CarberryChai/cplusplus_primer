//
// Created by 柴长林 on 2021/2/15.
//

#include <cctype>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<string> vec;
  string str;
  while (getline(std::cin, str)) vec.push_back(str);
  for (auto it = vec.begin(); it != vec.end() && !it->empty(); ++it) {
    for (auto &c : *it) c = toupper(c);
    std::cout << *it << std::endl;
  }
}