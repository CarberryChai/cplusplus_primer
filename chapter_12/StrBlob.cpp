//
// Created by 柴长林 on 2021/9/7.
//

#include "StrBlob.h"

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <vector>

#include "StrBlobPtr.h"
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> ils)
    : data(std::make_shared<std::vector<std::string>>(ils)) {}

void StrBlob::check(size_type idx, const std::string& msg) const {
  if (idx >= data->size()) {
    throw std::out_of_range(msg);
  }
}

std::string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }