//
// Created by 柴长林 on 2021/4/18.
//
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using namespace std::placeholders;

bool check_size(const std::string& s, string::size_type sz) {
  return s.size() <= sz;
}
int main() {
  vector<int> ivec{1, 3, 4, 5, 6, 7};
  auto it = std::find_if(ivec.cbegin(), ivec.cend(),
                         std::bind(check_size, "chai", _1));
  if (it == ivec.cend())
    std::cout << "not found" << std::endl;
  else
    std::cout << *it << std::endl;
}