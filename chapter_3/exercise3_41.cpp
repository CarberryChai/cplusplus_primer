//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <iterator>
#include <vector>

using std::begin;
using std::end;
using std::vector;

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> ivec(begin(arr), end(arr));
  for (int x : ivec) std::cout << x << " ";
}