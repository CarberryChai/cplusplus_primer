//
// Created by 柴长林 on 2021/2/13.
//
#include <iostream>

#include "../include/Sales_data.h"
int main() {
  Sales_data item, curItem;
  if (std::cin >> item.isbn) {
    int inc = 1;
    while (std::cin >> curItem.isbn) {
      if (item.isbn == curItem.isbn)
        inc++;
      else {
        std::cout << "the number of " << item.isbn << " is " << inc
                  << std::endl;
        item = curItem;
        inc = 1;
      }
    }
    std::cout << "the number of " << item.isbn << " is " << inc << std::endl;
  }
}