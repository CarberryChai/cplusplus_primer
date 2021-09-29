//
// Created by 柴长林 on 2021/9/29.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_13_MYSTRING_H_
#define CPLUSPLUS_PRIMER_CHAPTER_13_MYSTRING_H_

#include <cstddef>
#include <memory>
#include <utility>
class MyString {
 public:
  MyString() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  MyString(const char* chs);
  // copy constructor
  MyString(const MyString&);
  // copy-assignment
  MyString& operator=(const MyString&);
  // move constructor
  MyString(MyString&&) noexcept;
  // move-assignment
  MyString& operator=(MyString&&) noexcept;
  ~MyString();
  void push_back(const char&);
  char* begin() const { return elements; }
  char* end() const { return first_free; }
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }

 private:
  static std::allocator<char> alloc;
  void check_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }
  std::pair<char*, char*> alloc_n_copy(const char* begin, const char* end);
  void reallocate();
  void free();
  char* elements;
  char* first_free;
  char* cap;
};

#endif  // CPLUSPLUS_PRIMER_CHAPTER_13_MYSTRING_H_
