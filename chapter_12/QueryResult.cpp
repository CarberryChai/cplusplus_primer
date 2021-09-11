//
// Created by 柴长林 on 2021/9/11.
//
#include "QueryResult.h"

#include <ostream>

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.search_text << " occurs " << qr.lines->size()
     << (qr.lines->size() > 1 ? "times" : "time") << std::endl;
  for (auto num : *qr.lines) {
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num)
       << std::endl;
  }
  return os;
}
