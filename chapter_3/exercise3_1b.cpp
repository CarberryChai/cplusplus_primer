//
// Created by 柴长林 on 2021/2/13.
//
#include <iostream>

#include "../include/Sales_data.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int main() {
  Sales_data total;
  if (cin >> total.isbn >> total.units_sold >> total.revenue) {
    Sales_data curItem;
    while (cin >> curItem.isbn >> curItem.units_sold >> curItem.revenue) {
      if (total.isbn == curItem.isbn) {
        total.units_sold += curItem.units_sold;
        total.revenue += curItem.revenue;
      } else {
        cout << total.isbn << " " << total.units_sold << " " << total.revenue
             << endl;
        total = curItem;
      }
    }
    cout << total.isbn << " " << total.units_sold << " " << total.revenue
         << endl;
  } else {
    cerr << " No Data ? " << endl;
    return -1;
  }
  return 0;
}