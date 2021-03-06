//
// Created by 柴长林 on 2021/3/6.
//
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

bool valid(const string& s) {
  if (s.empty()) return false;
  return isnumber(s[0]);
}
string format(const string& s) {
  return s.substr(0, 3) + "-" + s.substr(3, 3) + "-" + s.substr(6);
}

struct PersonInfo {
  string name;
  vector<string> phones;
};

int main() {
  string line, word;
  vector<PersonInfo> people;
  std::istringstream record;
  const string url =
      "/Users/chaichanglin/Desktop/learn-demo/cplusplus_primer/data/"
      "phone_numbers.txt";
  std::ifstream ifs(url);
  while (getline(ifs, line)) {
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
    std::ostringstream formatted, badNums;
    for (const auto& nums : person.phones) {
      if (!valid(nums)) {
        badNums << " " << nums;
      } else {
        formatted << " " << format(nums);
      }
    }
    if (badNums.str().empty()) {
      std::cout << person.name << " " << formatted.str() << std::endl;
    } else {
      std::cerr << "input error: " << person.name << " invalid number(s) "
                << badNums.str() << std::endl;
    }
  }
}