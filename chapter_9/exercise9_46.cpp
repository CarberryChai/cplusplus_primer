//
// Created by 柴长林 on 2021/3/25.
//
#include <iostream>

using std::string;

string add_prefix_suffix(string& name, const string& prefix,
                         const string& suffix) {
  return name.insert(0, prefix).insert(name.size(), suffix);
}
int main() {
  string name("Carberry");
  std::cout << add_prefix_suffix(name, "Mr. ", ", Jr.") << std::endl;
}