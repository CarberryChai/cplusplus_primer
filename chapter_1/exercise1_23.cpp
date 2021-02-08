//
// Created by 柴长林 on 2021/2/8.
//

#include <iostream>

#include "Sales_item/Sales_item.h"

int main() {
  Sales_item item, curItem;
  if (std::cin >> item) {
    int inc = 1;
    while (std::cin >> curItem) {
      if (item.isbn() == curItem.isbn())
        inc++;
      else {
        std::cout << "the number of " << item.isbn() << " is " << inc
                  << std::endl;
        item = curItem;
        inc = 1;
      }
    }
    std::cout << "the number of " << item.isbn() << " is " << inc << std::endl;
  }
}