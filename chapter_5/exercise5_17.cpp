//
// Created by 柴长林 on 2021/2/21.
//
#include <iostream>
#include <vector>

using std::vector;

bool isPrefix(vector<int> &vec1, vector<int> &vec2) {
  auto smaller_size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
  for (decltype(vec1.size()) ix = 0; ix < smaller_size; ++ix) {
    if (vec1[ix] != vec2[ix]) return false;
  }
  return true;
}
int main() {
  vector<int> vec1{1, 2, 3, 4, 5}, vec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
  const char *msg = isPrefix(vec1, vec2) ? "is prefix" : "is not prefix";
  std::cout << msg << std::endl;
}