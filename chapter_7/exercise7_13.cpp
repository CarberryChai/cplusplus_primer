//
// Created by 柴长林 on 2021/2/28.
//
#include <iostream>

#include "../include/Sales_data.h"
using std::cin;
int main() {
  Sales_data total(cin);
  if (cin) {
    while (cin) {
      Sales_data curItem(cin);
      // 防止读取失败curItem默认初始化,这样total等于一个默认初始化的Sales_data对象
      // 这样循环退出时,print(std::cout, total)时在求avg_price时报错
      if (!cin) break;
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