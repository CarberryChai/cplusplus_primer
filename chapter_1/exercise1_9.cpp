//
// Created by 柴长林 on 2021/2/5.
//
#include <iostream>
int sum(int start, int end) {
  int sum = 0;
  while (start <= end) sum += start++;
  return sum;
}
int main() { std::cout << sum(1, 100) << std::endl; }