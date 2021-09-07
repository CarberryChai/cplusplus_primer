//
// Created by 柴长林 on 2021/4/21.
//
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>

using std::string;

const string& strim(string& s) {
  for (auto& ch : s) {
    ch = tolower(ch);
  }
  s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
  return s;
}
int main() {
  std::map<string, size_t> words_counter;
  string s;
  while (std::cin >> s) {
    if (!s.empty()) ++words_counter[strim(s)];
  }
  std::for_each(
      words_counter.begin(), words_counter.end(), [](const auto& word) {
        std::cout << word.first << " occurred " << word.second
                  << (word.second > 1 ? " times" : " time") << std::endl;
      });
}