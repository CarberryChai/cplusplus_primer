//
// Created by 柴长林 on 2021/9/18.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_13_STRVEC_H_
#define CPLUSPLUS_PRIMER_CHAPTER_13_STRVEC_H_

#include <cstddef>
#include <memory>
#include <string>
#include <utility>
class StrVec {
 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  ~StrVec();
  void push_back(const std::string &);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  void reserve(size_t);
  void resize(size_t);
  void resize(size_t, const std::string &);
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

 private:
  static std::allocator<std::string> alloc;
  void check_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }
  // utilities used by the copy constructor, assignment operator, and destructor
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  // get more space and copy the existing elements
  void reallocate();
  // destory the elements and free the space
  void free();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

#endif  // CPLUSPLUS_PRIMER_CHAPTER_13_STRVEC_H_
