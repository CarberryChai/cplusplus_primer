//
// Created by 柴长林 on 2021/3/5.
//
#include <iostream>

using std::istream;

template <typename T>
istream& read_all(istream& input, T value) {
  while (input >> value && !input.eof()) {
    std::cout << value << std::endl;
  }
  input.clear();
  return input;
}

int main() {
  std::string s;
  read_all(std::cin, s);
}