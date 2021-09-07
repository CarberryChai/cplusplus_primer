//
// Created by 柴长林 on 2021/2/15.
//
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
void print_vector(const vector<int> &vec) {
  cout << vec.size() << " ";
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) cout << *it << " ";
  cout << endl;
}
void print_vector(const vector<string> &vec) {
  cout << vec.size() << " ";
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) cout << *it << " ";
  cout << endl;
}
int main() {
  vector<int> v1;               // zero
  vector<int> v2(10);           // v2 has ten elements with value 0
  vector<int> v3(10, 42);       // v3 has ten elements with value 42
  vector<int> v4{10};           // v4 has one element with 10
  vector<int> v5{10, 42};       // v5 has two elements with value 10 and 42
  vector<string> v6{10};        // v6  has ten elements with value ""
  vector<string> v7{10, "hi"};  // v7 has ten elements with value "hi"

  print_vector(v1);
  print_vector(v2);
  print_vector(v3);
  print_vector(v4);
  print_vector(v5);
  print_vector(v6);
  print_vector(v7);
}