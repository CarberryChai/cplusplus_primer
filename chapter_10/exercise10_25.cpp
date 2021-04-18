//
// Created by 柴长林 on 2021/4/18.
//
//
// Created by 柴长林 on 2021/4/16.
//
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std::placeholders;
using std::string;
using std::vector;

bool check_size(const std::string& s, string::size_type sz) {
  return s.size() <= sz;
}

string make_plural(size_t ctr, const string& words, const string& ending) {
  return ctr > 1 ? words + ending : words;
}
void elimDups(vector<string>& words) {
  std::sort(words.begin(), words.end());
  words.erase(std::unique(words.begin(), words.end()), words.end());
}
void biggies(vector<string>& words, vector<string>::size_type sz) {
  elimDups(words);
  std::stable_sort(
      words.begin(), words.end(),
      [](const string& a, const string& b) { return a.size() < b.size(); });
  auto wc = std::stable_partition(words.begin(), words.end(),
                                  std::bind(check_size, _1, sz));
  auto count = wc - words.begin();
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;
  std::for_each(words.begin(), wc,
                [](const string& s) { std::cout << s << " "; });
}

int main() {
  vector<string> svec{"the",  "quick", "red",  "fox", "jumps",
                      "over", "the",   "slow", "red", "turtle"};
  biggies(svec, 4);
}