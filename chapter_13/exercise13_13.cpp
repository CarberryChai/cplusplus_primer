//
// Created by 柴长林 on 2021/9/12.
//
#include <iostream>
#include <vector>

using std::vector;
void log(const char *msg) { std::cout << msg << std::endl; }

struct X {
  X() { log("X()"); }
  X(const X &) { log("X(const X&)"); }
  X &operator=(const X &) {
    log("X& operator=(const X &)");
    return *this;
  }
  ~X() { log("~X()"); }
};
void foo(const X &a, X b) {
  vector<X> vec;
  vec.push_back(a);
  vec.push_back(b);
}
int main() {
  X *p = new X;
  foo(*p, *p);
  delete p;
}