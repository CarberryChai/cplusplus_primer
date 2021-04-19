//
// Created by 柴长林 on 2021/4/19.
//
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using std::string;
using std::vector;

int main() {
  const string url =
      "/Users/chaichanglin/Desktop/learn-demo/cplusplus_primer/data/"
      "test_10_29.txt";
  std::ifstream in(url);
  std::istream_iterator<string> iter(in), eof;
  vector<string> vec(iter, eof);
  std::for_each(vec.cbegin(), vec.cend(),
                [](const string& s) { std::cout << s << std::endl; });
}