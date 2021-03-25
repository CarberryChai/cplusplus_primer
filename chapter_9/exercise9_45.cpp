//
// Created by 柴长林 on 2021/3/25.
//
#include <iostream>

using std::string;

string add_prefix_suffix(string& name, const string& prefix,
                         const string& suffix) {
  name.insert(name.begin(), prefix.cbegin(), prefix.cend());
  return name.append(suffix);
}
int main() {
  string name("Carberry");
  std::cout << add_prefix_suffix(name, "Mr. ", ", Jr.") << std::endl;
}