//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>
using std::string;
int main() {
  string s1, s2;
  if (std::cin >> s1 >> s2) {
    if (s1 != s2) {
      string bigger = s1 > s2 ? s1 : s2;
      std::cout << "The bigger string is " << bigger << std::endl;
    }
  } else {
    std::cerr << "Please try again" << std::endl;
    return -1;
  }
  return 0;
}