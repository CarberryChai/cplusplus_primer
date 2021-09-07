//
// Created by 柴长林 on 2021/4/26.
//
#include <algorithm>
#include <iostream>
#include <map>

using std::multimap;
using std::string;

void print(const multimap<string, string>& m) {
  for (const auto& [key, value] : m) {
    std::cout << "key: " << key << ", value: " << value << std::endl;
  }
}
int main() {
  multimap<string, string> book_store;
  string author, work;
  while (std::cin >> author >> work) book_store.insert({author, work});
  std::cout << "input the name that you want to search for: " << std::endl;
  string search_item;
  std::cin.clear();
  if (std::cin >> search_item) {
    auto counts = book_store.count(search_item);
    auto it = book_store.find(search_item);
    while (counts) {
      it = book_store.erase(it);
      --counts;
    }
  }
  print(book_store);
}