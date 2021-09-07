//
// Created by 柴长林 on 2021/2/20.
//
#include <iostream>
#include <cctype>

using std::string;

int main() {
  string text;
  while (getline(std::cin, text) && !text.empty()) {
    unsigned acout = 0, ecout = 0, icout = 0, ocout = 0, ucout = 0;
    for (auto c : text) {
      if (tolower(c) == 'a')
        ++acout;
      else if (tolower(c) == 'e')
        ++ecout;
      else if (tolower(c) == 'i')
        ++icout;
      else if (tolower(c) == 'o')
        ++ocout;
      else if (tolower(c) == 'u')
        ++ucout;
    }
    std::cout << "The number of a vowel is " << acout << std::endl;
    std::cout << "The number of e vowel is " << ecout << std::endl;
    std::cout << "The number of i vowel is " << icout << std::endl;
    std::cout << "The number of o vowel is " << ocout << std::endl;
    std::cout << "The number of u vowel is " << ucout << std::endl;
  }
}