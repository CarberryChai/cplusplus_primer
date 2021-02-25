//
// Created by 柴长林 on 2021/2/25.
//
#include <cctype>
#include <iostream>
using std::string;
bool is_some_capital(const string &str) {
  for (const auto &c : str) {
    if (isupper(c)) return true;
  }
  return false;
}
void str2lower(string &str) {
  for (auto &c : str) c = tolower(c);
}
int main() {
  string s;
  if (std::cin >> s) {
    string msg = is_some_capital(s) ? "have some capital" : "no capital";
    std::cout << msg << std::endl;
  }
  std::cout << "****************" << std::endl;
  std::cout << "Please enter a string to transfer lowcase: " << std::endl;
  string s1;
  std::cin >> s1;
  str2lower(s1);
  std::cout << s1 << std::endl;
}