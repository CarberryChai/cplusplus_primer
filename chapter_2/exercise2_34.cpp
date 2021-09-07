//
// Created by 柴长林 on 2021/2/13.
//
#include <iostream>

int main() {
  int i = 0, &r = i;
  auto a = r;  // a is int
  const int ci = i, &cr = ci;
  auto b = ci;   // b is int
  auto c = cr;   // c is int
  auto d = &i;   // d is int*
  auto e = &ci;  // e is const int* (& of a const object is low-level const)
  const auto f = ci;  // f is const int
  auto &g = ci;
  a = 42;
  b = 42;
  c = 42;
  *d = 42;
  e = &b;
  // g = 42; // error: cannot assign to variable 'g' with const-qualified type
  // 'const int &'
}