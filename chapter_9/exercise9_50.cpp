//
// Created by 柴长林 on 2021/3/26.
//
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
  vector<string> nums{"12", "3.5", "21", "8", "6.2"};
  int sum1 = 0;
  for (const auto& item : nums) {
    int val = std::stoi(item);
    sum1 += val;
  }
  std::cout << sum1 << std::endl;
  double sum2 = 0;
  for (const auto& item : nums) {
    double val = std::stod(item);
    sum2 += val;
  }
  std::cout << sum2 << std::endl;
}