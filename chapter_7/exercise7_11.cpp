//
// Created by 柴长林 on 2021/2/28.
//
#include <iostream>
#include <vector>

#include "../include/Sales_data.h"
using std::vector;

int main() {
  Sales_data s1;
  Sales_data s2("abcdef");
  Sales_data s3("abcd", 5, 6.8);
  Sales_data s4(std::cin);
  for (const auto &item : vector<Sales_data>{s1, s2, s3, s4}) {
    print(std::cout, item) << std::endl;
  }
}