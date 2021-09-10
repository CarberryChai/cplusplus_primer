//
// Created by 柴长林 on 2021/9/7.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_12_STRBLOB_H_
#define CPLUSPLUS_PRIMER_CHAPTER_12_STRBLOB_H_

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
class StrBlobPtr;
class StrBlob {
 public:
  using size_type = std::vector<std::string>::size_type;
  friend class StrBlobPtr;
  StrBlobPtr begin();
  StrBlobPtr end();
  StrBlob();
  StrBlob(std::initializer_list<std::string> ils);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string& s) { data->push_back(s); }
  void pop_back();
  std::string& front();
  const std::string& front() const;
  std::string& back();
  const std::string& back() const;

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type idx, const std::string& msg) const;
};

#endif  // CPLUSPLUS_PRIMER_CHAPTER_12_STRBLOB_H_
