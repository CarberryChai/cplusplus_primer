//
// Created by 柴长林 on 2021/2/28.
//
#include "../include/Person.h"

#include <iostream>
Person::Person(std::istream& is) { is >> name >> address; }
std::istream& read(std::istream& input, Person& p) {
  input >> p.name >> p.address;
  return input;
}

std::ostream& write(std::ostream& output, Person& p) {
  output << p.name << " " << p.address;
  return output;
}