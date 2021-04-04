//
// Created by 柴长林 on 2021/3/25.
//
#include <iostream>
#include <vector>

using std::string;
using std::vector;

void find_number(const string& s, vector<char>& vec) {
  string nums("0123456789");
  size_t i = 0;
  while ((i = s.find_first_of(nums, i)) != string::npos) {
    vec.push_back(s[i]);
    ++i;
  }
}

void find_alpha(const string& s, vector<char>& vec) {
  string nums("0123456789");
  size_t i = 0;
  while ((i = s.find_first_not_of(nums, i)) != string::npos) {
    vec.push_back(s[i]);
    ++i;
  }
}

int main() {
  vector<char> n;
  find_number("ab2c3d7R4E6", n);
  for (auto item : n) {
    std::cout << item << " ";
  }
  std::cout << "\n**************\n";
  vector<char> a;
  find_alpha("ab2c3d7R4E6", a);
  for (auto item : a) {
    std::cout << item << " ";
  }
}