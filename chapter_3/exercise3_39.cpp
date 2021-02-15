//
// Created by 柴长林 on 2021/2/15.
//
#include <cstring>
#include <iostream>

using std::string;

int main() {
  string s1("hello world"), s2("hello world");
  if (s1 == s2)
    std::cout << "same string" << std::endl;
  else if (s1 < s2)
    std::cout << s1 << " less than " << s2 << std::endl;
  else
    std::cout << s1 << " greater than " << s2 << std::endl;

  std::cout << "*************************" << std::endl;
  const char *s3 = "hello world!!!", *s4 = "hello world";
  int compare_result = strcmp(s3, s4);
  if (compare_result == 0)
    std::cout << "same string" << std::endl;
  else if (compare_result < 0)
    std::cout << s3 << " less than " << s4 << std::endl;
  else
    std::cout << s3 << " greater than " << s4 << std::endl;
}