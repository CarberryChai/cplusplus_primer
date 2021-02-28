//
// Created by 柴长林 on 2021/2/28.
//

#ifndef CPLUSPLUS_PRIMER_INCLUDE_PERSON_H_
#define CPLUSPLUS_PRIMER_INCLUDE_PERSON_H_
#include <iostream>
struct Person {
  std::string name, address;
  const std::string& get_name() const { return name; }
  const std::string& get_address() const { return address; }

  Person() = default;
  Person(const std::string& name, const std::string& address)
      : name(name), address(address) {}
  Person(const std::string& name) : name(name) {}
  Person(std::istream& is);
};
std::istream& read(std::istream& input, Person& p);
std::ostream& write(std::ostream& output, Person& p);
#endif  // CPLUSPLUS_PRIMER_INCLUDE_PERSON_H_
