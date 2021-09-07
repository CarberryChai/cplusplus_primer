//
// Created by 柴长林 on 2021/4/23.
//
#include <iostream>
#include <map>

using std::map;
using std::string;

int main() {
  map<string, size_t> words_counter;
  string w;
  while (std::cin >> w) {
    auto [item, ok] = words_counter.insert({w, 1});
    if (!ok) ++item->second;
  }
  for (const auto& [word, count] : words_counter) {
    std::cout << word << " " << count << std::endl;
  }
}