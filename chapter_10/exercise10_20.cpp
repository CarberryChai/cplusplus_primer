//
// Created by 柴长林 on 2021/4/17.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
  // exercise 20
  vector<string> svec{"the", "carberry", "classic", "beautiful"};
  auto count = std::count_if(svec.begin(), svec.end(),
                             [](const string& s) { return s.size() >= 6; });
  std::cout << count << std::endl;
  // exercise 21
  int x = 10;
  auto fn = [&]() -> bool {
    if (x == 0) return true;
    --x;
    return false;
  };
  while (!fn())
    ;
  std::cout << "now x is " << x << std::endl;
}