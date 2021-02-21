//
// Created by 柴长林 on 2021/2/21.
//
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<string> words;
  string word;
  while (std::cin >> word) words.push_back(word);
  string duplicate = words[0], cur_duplicate = words[0];
  unsigned max_word = 1, cur_max = 1;
  for (decltype(word.size()) idx = 1; idx < words.size(); ++idx) {
    if (words[idx] == cur_duplicate)
      ++cur_max;
    else {
      if (cur_max > max_word) {
        max_word = cur_max;
        duplicate = cur_duplicate;
      }
      cur_duplicate = words[idx];
      cur_max = 1;
    }
  }
  if (max_word > 1)
    std::cout << "the word " << duplicate << " occurred " << max_word
              << " times. " << std::endl;
  else
    std::cout << "no word was repeated" << std::endl;
}