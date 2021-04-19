//
// Created by 柴长林 on 2021/4/19.
//
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::deque;
using std::list;
using std::vector;

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> ivec;
  list<int> lst;
  deque<int> que;
  std::copy(vec.begin(), vec.end(), std::back_inserter(ivec));
  // 1 2 3 4 5 6 7 8 9
  std::for_each(ivec.cbegin(), ivec.cend(),
                [](int i) { std::cout << i << " "; });

  std::copy(vec.cbegin(), vec.cend(), std::inserter(lst, lst.begin()));
  std::cout << std::endl;
  // 1 2 3 4 5 6 7 8 9
  std::for_each(lst.cbegin(), lst.cend(), [](int i) { std::cout << i << " "; });

  std::copy(vec.cbegin(), vec.cend(), std::front_inserter(que));
  std::cout << std::endl;
  // 9 8 7 6 5 4 3 2 1
  std::for_each(que.cbegin(), que.cend(), [](int i) { std::cout << i << " "; });
}