//
// Created by 柴长林 on 2021/3/6.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

int main() {
  const string url =
      "/Users/chaichanglin/Desktop/learn-demo/cplusplus_primer/data/books.txt";
  vector<string> lines;
  std::ifstream input(url);
  if (input) {
    string line;
    while (getline(input, line)) lines.push_back(line);
  }

  for (const auto& line : lines) {
    std::istringstream stream(line);
    string s;
    while (stream >> s) std::cout << s << " ";
    std::cout << std::endl;
    std::cout << "***read finished one line***" << std::endl;
  }
}