//
// Created by 柴长林 on 2021/4/15.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

bool isShorter(const string& s1, const string& s2) {
  return s1.size() < s2.size();
}
void elimDups(vector<string>& words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
  std::stable_sort(words.begin(), words.end(), isShorter);
}
int main() {
  vector<string> svec{"the",  "quick", "red",  "fox", "jumps",
                      "over", "the",   "slow", "red", "turtle"};
  elimDups(svec);
  for (const auto& item : svec) {
    std::cout << item << " ";
  }
}