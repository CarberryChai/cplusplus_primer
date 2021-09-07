//
// Created by 柴长林 on 2021/9/7.
//
#include <iostream>
#include <vector>
using std::vector;

vector<int>* getints() { return new vector<int>(); }
void read(std::istream& in, vector<int>* vec) {
  int x;
  while (in >> x) vec->push_back(x);
}
void print(std::ostream& out, vector<int>* vec) {
  for (auto i : *vec) out << i << " ";
}
int main() {
  auto p = getints();
  read(std::cin, p);
  print(std::cout, p);
  delete p;
}