//
// Created by 柴长林 on 2021/9/14.
//
#include <iostream>
#include <string>
class HasPtr {
 public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), count(new int(1)) {}
  HasPtr(const HasPtr &orig) : ps(orig.ps), i(orig.i), count(orig.count) {
    ++*count;
  }
  HasPtr &operator=(const HasPtr &rhs);
  ~HasPtr();
  int use_count() const { return *count; }

 private:
  std::string *ps;
  int i;
  int *count;
};
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  ++*rhs.count;
  if (--*count == 0) {
    delete ps;
    delete count;
  }
  ps = rhs.ps;
  i = rhs.i;
  count = rhs.count;
  return *this;
}
HasPtr::~HasPtr() {
  if (--*count == 0) {
    delete ps;
    delete count;
  }
}
int main() {
  HasPtr a("hello world");
  std::cout << a.use_count() << std::endl;
  HasPtr b(a);
  std::cout << b.use_count();
}