//
// Created by 柴长林 on 2021/3/24.
//
#include <iostream>

using std::string;

void replace_with(string& s, const string& oldValue, const string& newValue) {
  if (s.size() < oldValue.size()) return;
  auto it = s.begin();
  while (it != s.end() - oldValue.size()) {
    if (oldValue == string(it, it + oldValue.size())) {
      it = s.erase(it, it + oldValue.size());
      it = s.insert(it, newValue.cbegin(), newValue.cend());
      it += newValue.size();
    } else
      ++it;
  }
}

int main() {
  string s("hello world tho, carberry");
  replace_with(s, "tho", "though");
  std::cout << s << std::endl;
}