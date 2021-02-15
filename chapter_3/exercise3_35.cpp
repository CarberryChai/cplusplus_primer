//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <iterator>
int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *bg = std::begin(arr);
  int *end = std::end(arr);
  while (bg != end) {
    *bg = 0;
    bg++;
  }
  for (int x : arr) std::cout << x << " ";
}