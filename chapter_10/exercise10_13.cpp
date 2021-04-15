//
// Created by 柴长林 on 2021/4/15.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

bool at_least_five(const string& s) { return s.size() >= 5; }
int main() {
  vector<string> svec{"the",  "quick", "red",  "fox", "jumps",
                      "over", "the",   "slow", "red", "turtle"};
  auto it = std::partition(svec.begin(), svec.end(), at_least_five);
  for (auto iter = svec.begin(); iter != it; ++iter) std::cout << *iter << " ";
}