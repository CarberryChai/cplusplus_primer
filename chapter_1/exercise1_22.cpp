//
// Created by 柴长林 on 2021/2/8.
//

#include <iostream>

#include "Sales_item/Sales_item.h"

int main() {
  Sales_item total, curItem;
  while (std::cin >> curItem) total += curItem;
  std::cout << total << std::endl;
}