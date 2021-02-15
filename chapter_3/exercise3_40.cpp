//
// Created by 柴长林 on 2021/2/15.
//
#include <cstring>
#include <iostream>

int main() {
  char s1[] = "hello, ", s2[] = "carberry";
  char sum[] = {};
  strcpy(sum, strcat(s1, s2));
  std::cout << sum << std::endl;
}