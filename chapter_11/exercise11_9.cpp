//
// Created by 柴长林 on 2021/4/22.
//
#include <list>
#include <map>
#include <vector>
using namespace std;
int main() {
  // 11.9
  map<string, list<size_t>> mp;
  // 11.10
  map<vector<int>::iterator, int> mvp;
  map<list<int>::iterator, int> mlp;

  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  mvp.insert({vec.begin(), 0});

  list<int> lst{1, 2, 3, 4, 5};
  // error: invalid operands to binary expression
  mlp.insert({lst.begin(), 0});
}