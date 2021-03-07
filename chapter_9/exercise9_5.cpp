//
// Created by 柴长林 on 2021/3/7.
//
#include <iostream>
#include <vector>

using std::vector;

vector<int>::const_iterator find(vector<int>::const_iterator begin,
                                 vector<int>::const_iterator end, int value) {
  while (begin != end) {
    if (*begin == value) return begin;
    begin++;
  }
  return end;
}

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::string msg =
      find(vec.cbegin(), vec.cend(), 10) != vec.cend() ? "found" : "not found";
  std::cout << msg << std::endl;
}