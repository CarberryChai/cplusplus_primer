//
// Created by 柴长林 on 2021/3/4.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_57_H_
#define CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_57_H_
#include <iostream>
class Account {
 public:
  void calculate(interestRate) { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);

 private:
  std::string owner;
  double amount;
  static double interestRate;
};

void Account::rate(double newRate) { interestRate = newRate; }
double Account::interestRate = 0.41;
#endif  // CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_57_H_
