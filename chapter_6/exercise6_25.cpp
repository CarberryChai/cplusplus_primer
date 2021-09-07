//
// Created by 柴长林 on 2021/2/26.
//
#include <iostream>

int main(int argc, char** argv) {
  std::cout << argc << std::endl;
  std::string s;
  for (int i = 1; i < argc; ++i) {
    s += argv[i];
    s += " ";
  }
  std::cout << s << std::endl;
}