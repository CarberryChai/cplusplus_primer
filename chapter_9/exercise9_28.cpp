//
// Created by 柴长林 on 2021/3/15.
//
#include <forward_list>
#include <iostream>

using std::forward_list;
using std::string;

void find_and_insert(forward_list<string>& fst, const string& s1,
                     const string& s2) {
  auto it1 = fst.before_begin();
  auto it2 = fst.begin();
  while (it2 != fst.end()) {
    it1 = it2;
    if (*it2 == s1) break;
    ++it2;
  }
  fst.insert_after(it1, s2);
}
int main() {
  forward_list<string> fst;
  string s;
  auto it = fst.before_begin();
  while (std::cin >> s) {
    it = fst.insert_after(it, s);
  }
  find_and_insert(fst, "chai", "carberry");
  for (const auto& item : fst) {
    std::cout << item << std::endl;
  }
}