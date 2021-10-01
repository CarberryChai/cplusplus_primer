//
// Created by 柴长林 on 2021/9/18.
//
#include "StrVec.h"

#include <memory>
#include <utility>

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec& orig) {
  auto data = alloc_n_copy(orig.begin(), orig.end());
  elements = data.first;
  first_free = cap = data.second;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::push_back(const std::string& s) {
  check_n_alloc();
  std::allocator_traits<std::allocator<std::string>>::construct(
      alloc, first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(
    const std::string* b, const std::string* e) {
  auto new_space = alloc.allocate(e - b);
  return {new_space, std::uninitialized_copy(b, e, new_space)};
}

void StrVec::free() {
  if (elements) {
    auto p = first_free;
    while (p != elements) {
      std::allocator_traits<std::allocator<std::string>>::destroy(alloc, --p);
    }
    alloc.deallocate(elements, cap - elements);
  }
}

void StrVec::reallocate() {
  const auto sz = size() ? 2 * size() : 1;
  auto new_space = alloc.allocate(sz);
  auto p = new_space;
  auto q = elements;
  while (q != first_free) {
    std::allocator_traits<std::allocator<std::string>>::construct(
        alloc, p++, std::move(*q++));
  }
  free();
  elements = new_space;
  first_free = p;
  cap = new_space + sz;
}

void StrVec::resize(size_t n, const std::string& s) {
  check_n_alloc();
  if (n <= size()) {
    auto ptr_last = first_free;
    while (ptr_last != elements + n) {
      std::allocator_traits<std::allocator<std::string>>::destroy(alloc,
                                                                  --ptr_last);
    }
    first_free = ptr_last;
  } else if (n < capacity()) {
    auto p = first_free;
    while (p != elements + n) {
      push_back("");
      ++p;
    }
    first_free = p;
  } else {
    auto new_space = alloc.allocate(n);
    auto new_fitst_free =
        std::uninitialized_copy(elements, first_free, new_space);
    free();
    while (new_fitst_free != new_space + n) {
      std::allocator_traits<std::allocator<std::string>>::construct(
          alloc, new_fitst_free++, s);
    }
    elements = new_space;
    first_free = cap = new_fitst_free;
  }
}

void StrVec::resize(size_t n) { resize(n, ""); }

void StrVec::reserve(size_t n) {
  if (n <= capacity()) return;
  auto new_space = alloc.allocate(n);
  auto ptr_last = std::uninitialized_copy(elements, first_free, new_space);
  free();
  elements = new_space;
  first_free = ptr_last;
  cap = elements + n;
}