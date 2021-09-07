//
// Created by 柴长林 on 2021/2/14.
//
#include <cctype>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> vstr;
  string str;
  while (cin >> str)
    if (!str.empty()) vstr.push_back(str);
  for (auto &s : vstr) {
    for (auto &c : s) c = toupper(c);
  }
  for (decltype(vstr.size()) index = 0; index != vstr.size(); ++index) {
    if (index != 0 && index % 8 == 0) cout << endl;
    cout << vstr[index] << " ";
  }
}