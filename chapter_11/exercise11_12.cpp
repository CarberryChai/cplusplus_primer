//
// Created by 柴长林 on 2021/4/22.
//
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<std::pair<string, int>> vec;
  string s;
  int x;
  while (std::cin >> s >> x) {
    // vec.push_back({s, x});
    // vec.push_back(std::make_pair(s, x));
    vec.emplace_back(s, x);
  }
  for (const auto& item : vec) {
    std::cout << item.first << " " << item.second << std::endl;
  }
}