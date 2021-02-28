//
// Created by 柴长林 on 2021/2/13.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_2_SALES_DATA_H_
#define CPLUSPLUS_PRIMER_CHAPTER_2_SALES_DATA_H_
#include <iostream>
struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data& rhs);
  double avg_price() const;
};
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
std::istream& read(std::istream& input, Sales_data& item);
std::ostream& print(std::ostream& output, Sales_data& item);
#endif  // CPLUSPLUS_PRIMER_CHAPTER_2_SALES_DATA_H_
