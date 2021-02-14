//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>
using std::string;
int main() {
  string s1, s2;
  if (std::cin >> s1 >> s2) {
    auto size1 = s1.size();
    auto size2 = s2.size();
    if (size1 != size2) {
      auto bigger = size1 > size2 ? size1 : size2;
      std::cout << "The size of bigger string is " << bigger << std::endl;
    } else
      std::cout << s1 << " and " << s2 << " have the same size" << std::endl;
  } else {
    std::cerr << "Please try again" << std::endl;
    return -1;
  }
  return 0;
}