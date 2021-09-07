//
// Created by 柴长林 on 2021/4/20.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::list;
using std::vector;

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  // 10.34
  std::for_each(vec.crbegin(), vec.crend(),
                [](int i) { std::cout << i << " "; });
  // 10.35
  std::cout << std::endl;
  auto it = std::prev(vec.cend());
  while (true) {
    std::cout << *it << " ";
    if (it == vec.cbegin()) break;
    it = std::prev(it);
  }
  // 10.36
  std::cout << std::endl;
  list<int> lst{1, 4, 0, 8, 4, 0, 2, 5};
  auto zero = std::find(lst.crbegin(), lst.crend(), 0);
  std::cout << std::distance(lst.crbegin(), zero) << std::endl;
  // 10.37
  vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list<int> lst2;
  std::copy(vec2.crbegin() + 3, vec2.crbegin() + 7, std::back_inserter(lst2));
  std::for_each(lst2.begin(), lst2.end(), [](int i) { std::cout << i << " "; });
}