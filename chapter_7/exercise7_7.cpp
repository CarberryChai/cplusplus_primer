//
// Created by 柴长林 on 2021/2/28.
//
#include <iostream>

#include "../include/Sales_data.h"

int main() {
  Sales_data total;
  if (read(std::cin, total)) {
    Sales_data curItem;
    while (read(std::cin, curItem)) {
      if (total.isbn() == curItem.isbn()) {
        total.combine(curItem);
      } else {
        print(std::cout, total) << std::endl;
        total = curItem;
      }
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << " No Data ? " << std::endl;
    return -1;
  }
  return 0;
}