//
// Created by 柴长林 on 2021/3/12.
//
#include <deque>
#include <iostream>
#include <list>

using std::deque;
using std::list;

void print(const deque<int>& d) {
  for (const int i : d) std::cout << i << " ";
}

int main() {
  list<int> l;
  int i;
  while (std::cin >> i) l.push_back(i);
  deque<int> even, odd;
  for (const int x : l) {
    if (x % 2 == 0)
      even.push_back(x);
    else
      odd.push_back(x);
  }
  print(even);
  std::cout << std::endl;
  print(odd);
}