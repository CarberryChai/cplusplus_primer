//
// Created by 柴长林 on 2021/2/23.
//
#include <iostream>
using std::string;

int main() {
  string repeated, current;
  if (std::cin >> repeated) {
    while (std::cin >> current) {
      if (current == repeated) {
        std::cout << "The repeated string is " << repeated << std::endl;
        break;
      }
      repeated = current;
    }
    if (std::cin.fail()) std::cout << "no words were repeated" << std::endl;
  }
}