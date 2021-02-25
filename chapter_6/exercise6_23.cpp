//
// Created by 柴长林 on 2021/2/25.
//
#include <iostream>

void print(int x) { std::cout << x << std::endl; }
void print(int *begin, const int *end) {
  while (begin != end) std::cout << *begin++ << std::endl;
}
void print(int (&arr)[2]) {
  for (const auto item : arr) {
    std::cout << item << std::endl;
  }
}
void print(int *bg, size_t sz) {
  for (int i = 0; i < sz; ++i) {
    std::cout << bg[i] << std::endl;
  }
}

int main() {
  int i = 0, j[2] = {0, 1};
  print(i);
  print(j, 2);
  print(std::begin(j), std::end(j));
  print(j);
}