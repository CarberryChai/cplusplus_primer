//
// Created by 柴长林 on 2021/2/28.
//
#include <iostream>

#include "../include/Sales_data.h"

int main() {
  Sales_data total;
  if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data curItem;
    while (std::cin >> curItem.bookNo >> curItem.units_sold >>
                    curItem.revenue) {
      if (total.isbn() == curItem.isbn()) {
       total.combine(curItem);
      } else {
        std::cout << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << std::endl;
        total = curItem;
      }
    }
    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue
              << std::endl;
  } else {
    std::cerr << " No Data ? " << std::endl;
    return -1;
  }
  return 0;
}