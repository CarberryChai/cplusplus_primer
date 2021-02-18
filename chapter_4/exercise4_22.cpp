//
// Created by 柴长林 on 2021/2/18.
//
#include <iostream>

int main() {
  unsigned grade = 0;
  if (std::cin >> grade) {
    if (grade <= 100) {
      std::string final_grade = grade > 90      ? "high pass"
                                : (grade < 60)  ? "fail"
                                : (grade <= 75) ? "low pass"
                                                : "pass";
      std::cout << final_grade << std::endl;
    } else
      std::cerr << "unexpected grade" << std::endl;
  }
}