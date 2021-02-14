//
// Created by 柴长林 on 2021/2/14.
//
#include <iostream>
#include <vector>
using std::string;
using std::vector;
int main() {
  vector<int> v1;               // zero
  vector<int> v2(10);           // v2 has ten elements with value 0
  vector<int> v3(10, 42);       // v3 has ten elements with value 42
  vector<int> v4{10};           // v4 has one element with 10
  vector<int> v5{10, 42};       // v5 has two elements with value 10 and 42
  vector<string> v6{10};        // v6  has ten elements with value ""
  vector<string> v7{10, "hi"};  // v7 has ten elements with value "hi"

  std::cout << "The size of vector v1 is " << v1.size() << std::endl;
  std::cout << "The size of vector v2 is " << v2.size() << std::endl;
  std::cout << "The size of vector v3 is " << v3.size() << std::endl;
  std::cout << "The size of vector v4 is " << v4.size() << std::endl;
  std::cout << "The size of vector v5 is " << v5.size() << std::endl;
  std::cout << "The size of vector v6 is " << v6.size() << std::endl;
  std::cout << "The size of vector v7 is " << v7.size() << std::endl;
}