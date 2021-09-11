//
// Created by 柴长林 on 2021/9/11.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_12_QUERYRESULTSTRBLOB_H_
#define CPLUSPLUS_PRIMER_CHAPTER_12_QUERYRESULTSTRBLOB_H_

#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

#include "StrBlob.h"
#include "TextQueryStrBlob.h"
class QueryResultStrBlob {
  friend std::ostream& print(std::ostream&, const QueryResultStrBlob&);

 public:
  QueryResultStrBlob(const std::string& s,
                     std::shared_ptr<std::set<TextQueryStrBlob::line_number>> p,
                     const StrBlob& f)
      : search_text(s), lines(p), file(f) {}

 private:
  std::string search_text;
  std::shared_ptr<std::set<TextQueryStrBlob::line_number>> lines;
  StrBlob file;
};
std::ostream& print(std::ostream&, const QueryResultStrBlob&);

#endif  // CPLUSPLUS_PRIMER_CHAPTER_12_QUERYRESULTSTRBLOB_H_
