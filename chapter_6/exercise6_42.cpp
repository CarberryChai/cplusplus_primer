//
// Created by 柴长林 on 2021/2/27.
//

#include <iostream>

using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
  return ctr > 1 ? word + ending : word;
}

int main() {
  std::cout << "singular version: " << std::endl;
  std::cout << make_plural(1, "success", "es") << " "
            << make_plural(1, "failure") << std::endl;
  std::cout << "plural version: " << std::endl;
  std::cout << make_plural(2, "success", "es") << " "
            << make_plural(2, "failure") << std::endl;
}