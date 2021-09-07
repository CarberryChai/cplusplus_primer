//
// Created by 柴长林 on 2021/4/23.
//
#include <iostream>
#include <map>
#include <utility>

using std::string;

int main() {
  std::multimap<string, string> families;
  string first, last;
  std::cout << "input your first name, last name and birth respectively: "
            << std::endl;
  while (std::cin >> first >> last) {
    families.insert({last, first});
  }
  for (const auto& [f, l] : families) {
    std::cout << f << " " << l << std::endl;
  }
}