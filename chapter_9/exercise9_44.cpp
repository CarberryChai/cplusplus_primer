//
// Created by 柴长林 on 2021/3/25.
//
#include <iostream>

using std::string;

void replaceWith(string& s, const string& oldValue, const string& newValue) {
  if (s.size() < oldValue.size()) return;
  size_t idx = 0;
  while (idx != s.size() - oldValue.size()) {
    if (oldValue == string(s, idx, oldValue.size())) {
      s.replace(idx, oldValue.size(), newValue);
      idx += newValue.size();
    } else
      ++idx;
  }
}

int main() {
  string s("hello world tho, carberry");
  replaceWith(s, "tho", "though");
  std::cout << s << std::endl;
}