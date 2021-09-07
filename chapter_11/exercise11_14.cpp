//
// Created by 柴长林 on 2021/4/22.
//
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using std::string;
using std::vector;

int main() {
  std::map<string, vector<std::pair<string, string>>> families;
  string first, last, birth;
  std::cout << "input your first name, last name and birth respectively: "
            << std::endl;
  while (std::cin >> first >> last >> birth) {
    families[last].emplace_back(first, birth);
  }
  for (const auto& item : families) {
    std::cout << item.first << " has " << item.second.size()
              << " children : " << std::endl;
    for (const auto& child : item.second) {
      std::cout << child.first << " " << child.second << std::endl;
    }
    std::cout << "*********************" << std::endl;
  }
}