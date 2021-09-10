//
// Created by 柴长林 on 2021/9/9.
//

#include "StrBlobPtr.h"

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "StrBlob.h"

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
    size_t i, const std::string& msg) const {
  auto result = wptr.lock();
  if (!result) {
    throw std::runtime_error("unbound StrBlob");
  }
  if (i >= result->size()) {
    throw std::out_of_range(msg);
  }
  return result;
}

std::string& StrBlobPtr::deref() const {
  auto p = check(curr, "derefence past end");
  return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}
bool StrBlobPtr::operator!=(const StrBlobPtr& rhs) const {
  return curr != rhs.curr;
}
