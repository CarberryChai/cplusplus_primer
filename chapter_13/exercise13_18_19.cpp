//
// Created by 柴长林 on 2021/9/13.
//
#include <iostream>
#include <string>
class Employee {
  std::string name_;
  int id_;
  static int number;

 public:
  Employee() : id_(number + 1) {}
  Employee(const std::string &name) : name_(name), id_(number + 1) {}
  Employee(const Employee &) = delete;
  Employee &operator=(const Employee &) = delete;
  const std::string &name() const { return name_; }
  int id() const { return id_; }
};

int Employee::number = 0;

int main() {
  Employee e1("chai");
  std::cout << e1.name() << " " << e1.id() << std::endl;
}