//
// Created by 柴长林 on 2021/9/11.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_12_TEXTQUERYSTRBLOB_H_
#define CPLUSPLUS_PRIMER_CHAPTER_12_TEXTQUERYSTRBLOB_H_

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "StrBlob.h"
class QueryResultStrBlob;
class TextQueryStrBlob {
 public:
  using line_number = std::vector<std::string>::size_type;
  explicit TextQueryStrBlob(std::ifstream& fin);
  QueryResultStrBlob query(const std::string&) const;

 private:
  StrBlob file;
  std::map<std::string, std::shared_ptr<std::set<line_number>>> mp;
};

#endif  // CPLUSPLUS_PRIMER_CHAPTER_12_TEXTQUERYSTRBLOB_H_
