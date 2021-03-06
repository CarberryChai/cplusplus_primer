//
// Created by 柴长林 on 2021/3/6.
//
#include <fstream>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
void read_all_file(const string& filename, vector<string>& vec) {
  std::ifstream in(filename);
  if (in) {
    string s;
    while (in >> s) {
      vec.push_back(s);
    }
  }
}
int main() {
  vector<string> lines;
  read_all_file("test.txt", lines);
  for (const auto& item : lines) {
    std::cout << item << " ";
  }
}