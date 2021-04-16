//
// Created by 柴长林 on 2021/4/16.
//
#include <algorithm>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

string make_plural(size_t ctr, const string& words, const string& ending) {
  return ctr > 1 ? words + ending : words;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
  std::stable_sort(
      words.begin(), words.end(),
      [](const string& a, const string& b) { return a.size() < b.size(); });
  auto wc = std::find_if(words.begin(), words.end(),
                         [sz](const string& a) { return a.size() >= sz; });
  auto count = words.end() - wc;
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;
  std::for_each(wc, words.end(),
                [](const string& s) { std::cout << s << " "; });
}

int main() {
  vector<string> svec{"the",  "quick", "red",  "fox", "jumps",
                      "over", "the",   "slow", "red", "turtle"};
  biggies(svec, 4);
}