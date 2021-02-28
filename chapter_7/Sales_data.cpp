//
// Created by 柴长林 on 2021/2/28.
//
#include "../include/Sales_data.h"

#include <iostream>

Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

double Sales_data::avg_price() const { return revenue / units_sold; }

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
std::istream& read(std::istream& input, Sales_data& item) {
  double price;
  input >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return input;
}
std::ostream& print(std::ostream& output, Sales_data& item) {
  output << item.bookNo << " " << item.units_sold << " " << item.revenue << " "
         << item.avg_price();
  return output;
}