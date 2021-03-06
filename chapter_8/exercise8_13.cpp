//
// Created by 柴长林 on 2021/3/6.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

struct PersonInfo {
  string name;
  vector<string> phones;
};

int main() {
  string line, word;
  vector<PersonInfo> people;
  std::istringstream record;
  while (getline(std::cin, line)) {
    PersonInfo info;
    // 第一次循环record流上的数据以及读完，此时record的state是无效的，需要重置状态
    record.clear(record.rdstate() & ~std::istringstream::eofbit &
                 ~std::istringstream::failbit);
    record.str(line);
    record >> info.name;
    while (record >> word) info.phones.push_back(word);
    people.push_back(info);
  }
  for (const auto& person : people) {
    std::cout << person.name << " ";
    for (const auto& p : person.phones) std::cout << p << " ";
    std::cout << std::endl;
  }
}