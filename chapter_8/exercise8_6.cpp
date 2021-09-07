//
// Created by 柴长林 on 2021/3/6.
//
#include <fstream>
#include <iostream>

#include "../include/Sales_data.h"

int main(int argc, char* argv[]) {
  Sales_data total;
  const std::string& root =
      "/Users/chaichanglin/Desktop/learn-demo/cplusplus_primer/data/";
  const std::string& url = root + argv[1];
  std::ifstream in(url);
  if (in && read(in, total)) {
    Sales_data curItem;
    while (read(in, curItem)) {
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