//
// Created by 柴长林 on 2021/4/19.
//
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#include "../include/Sales_item.h"

using std::string;
using std::vector;

int main() {
  const string url =
      "/Users/chaichanglin/Desktop/learn-demo/cplusplus_primer/data/"
      "books.txt";
  std::ifstream in(url);
  std::istream_iterator<Sales_item> iter(in), eof;
  vector<Sales_item> vec(iter, eof);
  std::sort(vec.begin(), vec.end(), compareIsbn);
  decltype(vec.begin()) first = vec.begin(), cur;
  Sales_item sum = vec[0];
  while ((cur = std::find_if(first, vec.end(), [&](const Sales_item& item) {
            return item.isbn() != first->isbn();
          })) != vec.end()) {
    std::cout << std::accumulate(first + 1, cur, sum) << std::endl;
    first = cur;
    sum = *cur;
  }
  std::cout << std::accumulate(first + 1, cur, sum) << std::endl;
}