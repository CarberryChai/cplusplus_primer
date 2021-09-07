//
// Created by 柴长林 on 2021/2/27.
//
#include <iostream>

void log(const char* msg) { std::cout << msg << std::endl; }

void f() { log("f()"); }
void f(int) { log("f(int)"); }
void f(int, int) { log("f(int, int)"); }
void f(double, double) { log("f(double, double)"); }

int main() {
  f(2.56, 42);
  f(42);
  f(0);
  f(2.56, 3.14);
}