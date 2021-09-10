//
// Created by 柴长林 on 2021/9/9.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_12_STRBLOBPTR_H_
#define CPLUSPLUS_PRIMER_CHAPTER_12_STRBLOBPTR_H_
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "StrBlob.h"
class StrBlobPtr {
 public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
  std::string& deref() const;
  StrBlobPtr& incr();
  bool operator!=(const StrBlobPtr& rhs) const;

 private:
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
  std::shared_ptr<std::vector<std::string>> check(size_t,
                                                  const std::string&) const;
};

#endif  // CPLUSPLUS_PRIMER_CHAPTER_12_STRBLOBPTR_H_
