//
// Created by 柴长林 on 2021/4/20.
//

#include <algorithm>
#include <iostream>
#include <list>

using std::list;
using std::string;

void elimDups(list<string>& words) {
  words.sort();
  words.unique();
}
int main() {
  list<string> lst{"the",  "quick", "red",  "fox", "jumps",
                   "over", "the",   "slow", "red", "turtle"};
  elimDups(lst);
  std::for_each(lst.begin(), lst.end(),
                [](const string& s) { std::cout << s << " "; });
}