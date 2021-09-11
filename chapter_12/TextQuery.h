//
// Created by 柴长林 on 2021/9/11.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_12_TEXTQUERY_H_
#define CPLUSPLUS_PRIMER_CHAPTER_12_TEXTQUERY_H_
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

class QueryResult;
class TextQuery {
 public:
  using line_number = std::vector<std::string>::size_type;
  explicit TextQuery(std::ifstream& fin);
  QueryResult query(const std::string&) const;

 private:
  std::shared_ptr<std::vector<std::string>> file =
      std::make_shared<std::vector<std::string>>();
  std::map<std::string, std::shared_ptr<std::set<line_number>>> mp;
};

#endif  // CPLUSPLUS_PRIMER_CHAPTER_12_TEXTQUERY_H_
