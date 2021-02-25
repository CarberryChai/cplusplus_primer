//
// Created by 柴长林 on 2021/2/24.
//
#include <iostream>

#include "../include/Chapter6.h"

int fact(int x) {
  if (x <= 1) return 1;
  return x * fact(x - 1);
}
void compute_fact() {
  std::cout << "Please input a integer to compute fact" << std::endl;
  int x;
  if (std::cin >> x) {
    std::cout << fact(x) << std::endl;
  }
}

int abs(int x) { return x >= 0 ? x : -x; }