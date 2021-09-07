//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>

int main() {
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  // iterator
  for (int(&row)[4] : ia)
    for (int col : row) std::cout << col << " ";

  // pointer
  std::cout << std::endl;
  for (int(*row)[4] = ia; row != ia + 3; ++row)
    for (int *col = *row; col != *row + 4; ++col) std::cout << *col << " ";

  // subscripts
  std::cout << std::endl;
  for (size_t i = 0; i < 3; ++i)
    for (size_t j = 0; j < 4; ++j) std::cout << ia[i][j] << " ";
}