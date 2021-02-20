//
// Created by 柴长林 on 2021/2/20.
//
#include <cctype>
#include <iostream>

using std::string;

int main() {
  string text;
  while (getline(std::cin, text) && !text.empty()) {
    unsigned acout = 0, ecout = 0, icout = 0, ocout = 0, ucout = 0,
             space_count = 0, two_char_count = 0;
    char ch = text[0];
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
      else if (isspace(c))
        ++space_count;
      else if (c == 'f' || c == 'l' || c == 'i') {
        two_char_count += ch == 'f' ? 1 : 0;
      }
      ch = c;
    }
    std::cout << "The number of a vowel is " << acout << std::endl;
    std::cout << "The number of e vowel is " << ecout << std::endl;
    std::cout << "The number of i vowel is " << icout << std::endl;
    std::cout << "The number of o vowel is " << ocout << std::endl;
    std::cout << "The number of u vowel is " << ucout << std::endl;
    std::cout << "The number of spaces is " << space_count << std::endl;
    std::cout << "The number of occurrences of the following two-character "
                 "sequences is "
              << two_char_count << std::endl;
  }
}