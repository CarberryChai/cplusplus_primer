//
// Created by 柴长林 on 2021/4/21.
//
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

int main() {
  std::map<string, vector<string>> families;
  string line;
  while (getline(std::cin, line)) {
    std::istringstream ip(line);
    vector<string> person((std::istream_iterator<string>(ip)),
                          std::istream_iterator<string>());
    families[person.at(1)].push_back(person.at(0));
  }
  for (const auto& item : families) {
    std::cout << item.first << " has " << item.second.size() << " children : ";
    for (const auto& second : item.second) {
      std::cout << second << " ";
    }
    std::cout << std::endl;
  }
}