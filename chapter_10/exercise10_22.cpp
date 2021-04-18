//
// Created by 柴长林 on 2021/4/18.
//
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using namespace std::placeholders;

bool is_shorter(const std::string& s, string::size_type sz) {
  return s.size() <= sz;
}
int main() {
  vector<string> svec{"the", "quick", "red", "fox", "jumps", "carberry"};
  auto count =
      std::count_if(svec.begin(), svec.end(), std::bind(is_shorter, _1, 6));
  std::cout << count << std::endl;
}