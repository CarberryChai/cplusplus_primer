//
// Created by 柴长林 on 2021/3/13.
//
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> v(std::cbegin(ia), std::cend(ia));
  list<int> l(std::cbegin(ia), std::cend(ia));
  auto it = v.begin();
  while (it != v.end()) {
    if (*it % 2 == 0)
      it = v.erase(it);
    else
      it++;
  }
  for (auto item : v) {
    std::cout << item << " ";
  }
}