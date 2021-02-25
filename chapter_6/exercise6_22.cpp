//
// Created by 柴长林 on 2021/2/25.
//
#include <iostream>

void swap_pointer(int **a, int **b) {
  int *temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int i = 5, j = 42;
  int *pi = &i, *pj = &j;
  swap_pointer(&pi, &pj);
  *pi += 1;
  std::cout << i << std::endl;
  std::cout << j << std::endl;
}