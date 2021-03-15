//
// Created by 柴长林 on 2021/3/15.
//
#include <forward_list>
#include <iostream>

using std::forward_list;

int main() {
  forward_list<int> flst;
  int i;
  auto it = flst.before_begin();
  while (std::cin >> i) it = flst.insert_after(it, i);
  it = flst.before_begin();
  auto it2 = flst.begin();
  while (it2 != flst.end()) {
    if (*it2 % 2)
      it2 = flst.erase_after(it);
    else {
      it = it2;
      ++it2;
    }
  }
  for (auto item : flst) {
    std::cout << item << " ";
  }
}