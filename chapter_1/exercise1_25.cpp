//
// Created by 柴长林 on 2021/2/8.
//
#include <iostream>

#include "../include/Sales_item.h"

int main() {
  Sales_item total;
  if (std::cin >> total) {
    Sales_item curItem;
    while (std::cin >> curItem) {
      if (total.isbn() == curItem.isbn())
        total += curItem;
      else {
        std::cout << total << std::endl;
        total = curItem;
      }
    }
    std::cout << total << std::endl;
  } else {
    std::cerr << " No Data ? " << std::endl;
    return -1;
  }
  return 0;
}