//
// Created by 柴长林 on 2021/9/11.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_12_QUERYRESULT_H_
#define CPLUSPLUS_PRIMER_CHAPTER_12_QUERYRESULT_H_

#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

#include "TextQuery.h"
class QueryResult {
  friend std::ostream& print(std::ostream&, const QueryResult&);

 public:
  QueryResult(const std::string& s,
              std::shared_ptr<std::set<TextQuery::line_number>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : search_text(s), lines(p), file(f) {}

 private:
  std::string search_text;
  std::shared_ptr<std::set<TextQuery::line_number>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};
std::ostream& print(std::ostream&, const QueryResult&);

#endif  // CPLUSPLUS_PRIMER_CHAPTER_12_QUERYRESULT_H_
