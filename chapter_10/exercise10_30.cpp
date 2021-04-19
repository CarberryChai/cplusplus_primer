//
// Created by 柴长林 on 2021/4/19.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

int main() {
  std::istream_iterator<int> iter(std::cin), eof;
  std::ostream_iterator<int> out(std::cout, " ");
  vector<int> vec(iter, eof);
  std::sort(vec.begin(), vec.end());
  // std::copy(vec.cbegin(), vec.cend(), out);
  std::unique_copy(vec.cbegin(), vec.cend(), out);
}