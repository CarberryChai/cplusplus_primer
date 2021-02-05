//
// Created by 柴长林 on 2021/2/4.
//
#include <iostream>
int sum(int stop) {
  int total = 0, i = 50;
  while (i <= stop) total += i++;
  return total;
}
int main() {
  // Exercise 1.3
  std::cout << "Hello, World" << std::endl;
  // Exercise 1.4
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "v1 = " << v1 << "; v2 = " << v2 << "; product is " << v1 * v2
            << std::endl;

  std::cout << sum(100) << std::endl;

  int t = 10;
  while (t >= 0) {
    std::cout << t-- << std::endl;
  }

  int x = 0, y = 0;
  std::cin >> x >> y;
  if (x >= y) {
    while (x >= y) std::cout << x-- << std::endl;
  } else {
    while (x <= y) {
      std::cout << x++ << std::endl;
    }
  }
  return 0;
}