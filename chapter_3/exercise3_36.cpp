//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <iterator>
#include <vector>

using std::begin;
using std::end;
using std::string;
using std::vector;
bool compare_array(const int *bg1, const int *end1, const int *bg2,
                   const int *end2) {
  if (end1 - bg1 != end2 - bg2) return false;
  while (bg1 != end1 && bg2 != end2) {
    if (*bg1 != *bg2) return false;
    bg1++;
    bg2++;
  }
  return true;
}
int main() {
  int arr1[] = {1, 2, 3, 4, 5}, arr2[] = {1, 2, 3, 4, 5};
  bool isEqual = compare_array(begin(arr1), end(arr1), begin(arr2), end(arr2));
  string msg = isEqual ? "The two arrays are equal" : "not equal";
  std::cout << msg << std::endl;

  std::cout << "***********************" << std::endl;
  vector<int> ivec1{1, 2, 3, 4, 5}, ivec2{1, 2, 3, 4, 5};
  string message =
      ivec1 == ivec2 ? "The two vector<int> are equal" : "not equal";
  std::cout << message << std::endl;
}