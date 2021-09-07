//
// Created by 柴长林 on 2021/4/25.
//
#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::string;
using std::vector;
int main() {
  map<string, vector<int>> map;
  map.insert({"hello", {1, 2}});
  auto it = map.find("hello");
  std::cout << it->first << std::endl;

  std::multimap<string, int> mp;
  mp.insert({"chai", 30});
  mp.insert({"chai", 20});
  mp.insert({"chai", 10});
  mp.insert({"carberry", 10});
  auto low = mp.lower_bound("mia"), high = mp.upper_bound("mia");
  auto range = mp.equal_range("mia");
  if (range == std::make_pair(low, high))
    std::cout << "no present" << std::endl;
}