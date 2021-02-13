//
// Created by 柴长林 on 2021/2/13.
//
#include <iostream>

#include "sales_data.h"

int main() {
  Sales_data total;
  if (std::cin >> total.isbn >> total.units_sold >> total.revenue) {
    Sales_data curItem;
    while (std::cin >> curItem.isbn >> curItem.units_sold >> curItem.revenue) {
      if (total.isbn == curItem.isbn) {
        total.units_sold += curItem.units_sold;
        total.revenue += curItem.revenue;
      } else {
        std::cout << total.isbn << " " << total.units_sold << " "
                  << total.revenue << std::endl;
        total = curItem;
      }
    }
    std::cout << total.isbn << " " << total.units_sold << " " << total.revenue
              << std::endl;
  } else {
    std::cerr << " No Data ? " << std::endl;
    return -1;
  }
  return 0;
}