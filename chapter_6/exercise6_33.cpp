//
// Created by 柴长林 on 2021/2/26.
//
#include <iostream>
#include <vector>

using std::string;
using std::vector;

void print_vector(vector<string>::iterator begin,
                  vector<string>::iterator end) {
#ifndef NDEBUG
  std::cout << "The range of vector is " << end - begin << std::endl;
#endif
  if (begin == end) return;
  std::cout << *begin << std::endl;
  print_vector(begin + 1, end);
}
int main() {
  vector<string> vec;
  string str;
  while (std::cin >> str) vec.push_back(str);
  print_vector(vec.begin(), vec.end());
}
