//
// Created by 柴长林 on 2021/4/19.
//
#include <fstream>
#include <iterator>

using std::string;
int main() {
  const string url =
      "/Users/chaichanglin/Desktop/learn-demo/cplusplus_primer/data/";
  std::ifstream f_in(url + "10_33_integer.txt");
  std::ofstream f_out_odd(url + "10_33_odd.txt"),
      f_out_even(url + "10_33_even.txt");
  std::istream_iterator<int> iter(f_in), eof;
  std::ostream_iterator<int> odd(f_out_odd, " "), even(f_out_even, "\n");
  while (iter != eof) {
    if (*iter % 2)
      *odd++ = *iter;
    else
      *even++ = *iter;
    iter++;
  }
}