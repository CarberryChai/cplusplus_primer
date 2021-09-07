//
// Created by 柴长林 on 2021/4/19.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::list;
using std::vector;

int main() {
  vector<int> ivec{1, 1, 3, 3, 4, 4, 4};
  list<int> ilst;
  std::unique_copy(ivec.begin(), ivec.end(), std::back_inserter(ilst));
  std::for_each(ilst.begin(), ilst.end(), [](int i) { std::cout << i << " "; });
}