//
// Created by 柴长林 on 2021/3/6.
//
#include <iostream>
#include <sstream>

using std::istream;
using std::istringstream;
using std::string;

istream& read_all(istream& input) {
  string value;
  while (input >> value) {
    std::cout << value << std::endl;
  }
  input.clear();
  return input;
}

int main() {
  string s("hello world!!!"), s1;
  istringstream in(s);
  read_all(in);
}