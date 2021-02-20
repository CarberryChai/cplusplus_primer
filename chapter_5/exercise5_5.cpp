//
// Created by 柴长林 on 2021/2/20.
//
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
  const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
  unsigned grade = 0;
  string letterGrade;
  while (std::cin >> grade) {
    if (grade <= 100) {
      if (grade < 60)
        letterGrade = scores[0];
      else {
        letterGrade = scores[(grade - 50) / 10];
        if (grade != 100) {
          if (grade % 10 > 7)
            letterGrade += '+';
          else if (grade % 10 < 3)
            letterGrade += '-';
        }
      }
    }
    std::cout << letterGrade << std::endl;
  }
}