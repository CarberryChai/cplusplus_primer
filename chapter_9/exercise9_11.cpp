//
// Created by 柴长林 on 2021/3/8.
//
#include <iostream>
#include <vector>

using std::vector;

int main() {
  // six ways to create and initialize a vector.
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // copy initializer list
  vector<int> v2 = v1;                            // copy assign initialization
  vector<int> v3(
      v1.begin(),
      v1.begin() +
          5);  // copy a range of elements denoted by a pair of iterators
  vector<int> v4(10);  // created with ten elements that are value initialized
  vector<int> v5(10, 1);  // created with 10 elements with explicit initializer
  vector<int> v6;         // empty vector
}