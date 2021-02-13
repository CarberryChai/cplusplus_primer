//
// Created by 柴长林 on 2021/2/13.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_2_SALES_DATA_H_
#define CPLUSPLUS_PRIMER_CHAPTER_2_SALES_DATA_H_
struct Sales_data {
  std::string isbn;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
#endif  // CPLUSPLUS_PRIMER_CHAPTER_2_SALES_DATA_H_
