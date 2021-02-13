//
// Created by 柴长林 on 2021/2/13.
//
#include <iostream>

#include "sales_data.h"
int main() {
  Sales_data s1, s2;
  std::cin >> s1.isbn >> s1.units_sold >> s1.revenue;
  std::cin >> s2.isbn >> s2.units_sold >> s2.revenue;
  if (s1.isbn == s2.isbn) {
    unsigned total_sold = s1.units_sold + s2.units_sold;
    double sum = s1.revenue + s2.revenue;
    std::cout << s1.isbn << " " << total_sold << " " << sum << " ";
    if (total_sold != 0)
      std::cout << sum / total_sold << std::endl;
    else
      std::cout << "no sales" << std::endl;
  } else {
    std::cerr << "Data must be refer to the same isbn" << std::endl;
    return -1;
  }
}