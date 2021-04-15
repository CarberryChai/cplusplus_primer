//
// Created by 柴长林 on 2021/4/15.
//
#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/Sales_data.h"
using std::string;
using std::vector;
bool compareIsbn(const Sales_data& b1, const Sales_data& b2) {
  return b1.isbn() < b2.isbn();
}
int main() {
  vector<Sales_data> books{Sales_data("0-201-78345-X"),
                           Sales_data("0-201-78346-X"),
                           Sales_data("0-201-78342-X")};
  std::sort(books.begin(), books.end(), compareIsbn);
  for (const auto& item : books) {
    std::cout << item.isbn() << " ";
  }
}