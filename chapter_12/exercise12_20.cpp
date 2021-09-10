//
// Created by 柴长林 on 2021/9/9.
//
#include <fstream>
#include <iostream>
#include <vector>

#include "StrBlob.h"
#include "StrBlobPtr.h"
int main() {
  StrBlob str_blob;
  std::string line;
  const std::string url =
      "/Users/chaichanglin/Desktop/learn-demo/cplusplus_primer/data/"
      "phone_numbers.txt";
  std::ifstream in(url);
  while (getline(in, line)) {
    str_blob.push_back(line);
  }
  for (auto begin = str_blob.begin(); begin != str_blob.end(); begin.incr()) {
    std::cout << begin.deref() << std::endl;
  }
}