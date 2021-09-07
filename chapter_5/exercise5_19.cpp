//
// Created by 柴长林 on 2021/2/21.
//
#include <iostream>

using std::string;

int main() {
  do {
    string s1, s2;
    if (std::cin >> s1 >> s2) {
      s1 < s2 ? std::cout << s1 << " is less than " << std::endl
              : std::cout << s2 << " is less than " << s1 << std::endl;
    }
  } while (std::cin);
}