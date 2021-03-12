//
// Created by 柴长林 on 2021/3/11.
//
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

bool is_equal(const vector<int>& v1, const vector<int>& v2) { return v1 == v2; }
bool is_equal(const list<int>& l1, const list<int>& l2) { return l1 == l2; }
int main() {
  vector<int> v1{1, 2, 3, 4, 5};
  vector<int> v2{1, 2, 3, 4, 6};

  const char* msg1 = is_equal(v1, v2) ? "equal" : "not equal";
  std::cout << msg1 << std::endl;

  std::cout << "*********************" << std::endl;

  list<int> l1{1, 2, 3, 4, 5};
  list<int> l2{1, 2, 3, 4, 5};

  const char* msg2 = is_equal(l1, l2) ? "equal" : "not equal";
  std::cout << msg2 << std::endl;
}