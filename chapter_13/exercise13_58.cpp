//
// Created by 柴长林 on 2021/9/29.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Foo {
 public:
  Foo(std::initializer_list<int> args) : data(args) {}
  Foo sorted() &&;
  Foo sorted() const &;

 private:
  vector<int> data;
};

Foo Foo::sorted() && {
  std::cout << "&&" << std::endl;
  std::sort(data.begin(), data.end());
  return *this;
}

Foo Foo::sorted() const & {
  std::cout << "const &" << std::endl;
  return Foo(*this).sorted();
}

int main() {
  Foo foo{3, 2, 5, 1};
  foo.sorted();
}