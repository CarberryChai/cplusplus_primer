//
// Created by 柴长林 on 2021/9/11.
//
#include "TextQueryStrBlob.h"

#include <fstream>
#include <memory>
#include <set>
#include <sstream>
#include <string>

#include "QueryResultStrBlob.h"
TextQueryStrBlob::TextQueryStrBlob(std::ifstream& filein) {
  std::string s;
  std::istringstream strStream;
  while (std::getline(filein, s)) {
    file.push_back(s);
    line_number idx = file.size() - 1;
    strStream.clear();
    strStream.str(s);
    std::string word;
    while (strStream >> word) {
      auto& lines = mp[word];
      if (!lines) lines.reset(new std::set<line_number>);
      lines->insert(idx);
    }
  }
}

QueryResultStrBlob TextQuery::query(const std::string& q) const {
  static std::shared_ptr<std::set<line_number>> not_found(
      new std::set<line_number>);
  auto result = mp.find(q);
  if (result == mp.end()) return QueryResultStrBlob(q, not_found, file);
  return QueryResultStrBlob(q, result->second, file);
}
