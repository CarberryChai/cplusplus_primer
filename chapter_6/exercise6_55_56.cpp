//
// Created by 柴长林 on 2021/2/27.
//
#include <iostream>
#include <vector>

using std::vector;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
  if (b == 0) throw std::runtime_error("division by zero");
  return a / b;
}

int main() {
  vector<decltype(add)*> fvec{add, subtract, multiply, divide};
  for (const auto f : fvec) std::cout << f(7, 2) << std::endl;
}