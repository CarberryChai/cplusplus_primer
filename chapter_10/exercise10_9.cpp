//
// Created by 柴长林 on 2021/4/14.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

void print_vector(const vector<string>& vec) {
  for (const auto& item : vec) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
void elimDups(vector<string>& words) {
  print_vector(words);
  std::sort(words.begin(), words.end());
  print_vector(words);
  auto end_unique = std::unique(words.begin(), words.end());
  print_vector(words);
  words.erase(end_unique, words.end());
  print_vector(words);
}
int main() {
  vector<string> svec;
  string s;
  while (std::cin >> s) svec.push_back(s);
  elimDups(svec);
}