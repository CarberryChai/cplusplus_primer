//
// Created by 柴长林 on 2021/2/13.
//
#include <iostream>

#include "../include/Sales_data.h"
int main() {
  Sales_data item, curItem;
  if (std::cin >> item.bookNo) {
    int inc = 1;
    while (std::cin >> curItem.bookNo) {
      if (item.bookNo == curItem.bookNo)
        inc++;
      else {
        std::cout << "the number of " << item.bookNo << " is " << inc
                  << std::endl;
        item = curItem;
        inc = 1;
      }
    }
    std::cout << "the number of " << item.bookNo << " is " << inc << std::endl;
  }
}