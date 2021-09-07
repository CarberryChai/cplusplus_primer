//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  const vector<int> cvec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  const size_t sz = cvec.size();
  int arr[sz];
  for (auto i = 0; i < sz; ++i) arr[i] = cvec[i];
  for (int x : arr) std::cout << x << " ";
}