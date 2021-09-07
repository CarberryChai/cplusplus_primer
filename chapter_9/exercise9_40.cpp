//
// Created by 柴长林 on 2021/3/22.
//
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<string> svec;
  svec.reserve(1024);
  for (int i = 0; i < 1048; ++i) {
    svec.emplace_back("a");
  }
  svec.resize(svec.size() + svec.size() / 2);
  std::cout << "size: " << svec.size() << "; capacity: " << svec.capacity()
            << std::endl;
}