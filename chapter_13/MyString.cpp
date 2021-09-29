//
// Created by 柴长林 on 2021/9/29.
//
#include "MyString.h"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <utility>
std::allocator<char> MyString::alloc;

MyString::MyString(const char* ch) {
  std::cout << "MyString const char constructor" << std::endl;
  auto size = std::strlen(ch);
  auto new_space = alloc.allocate(size);
  while (ch && *ch != '\0') {
    std::allocator_traits<std::allocator<char>>::construct(alloc, new_space,
                                                           *ch++);
  }
  elements = new_space;
  first_free = cap = new_space + size;
}
// copy constructor
MyString::MyString(const MyString& orig) {
  auto data = alloc_n_copy(orig.begin(), orig.end());
  std::cout << "MyString copy constructor is called" << std::endl;
  elements = data.first;
  first_free = cap = data.second;
}
// copy-assignment
MyString& MyString::operator=(const MyString& rhs) {
  std::cout << "MyString copy-assignment is called" << std::endl;
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

// move constructor
MyString::MyString(MyString&& other) noexcept
    : elements(other.elements), first_free(other.first_free), cap(other.cap) {
  std::cout << "MyString move constructor is called" << std::endl;
  other.elements = other.first_free = other.cap = nullptr;
}

// move-assignment
MyString& MyString::operator=(MyString&& other) noexcept {
  std::cout << "MyString move-assignment is called" << std::endl;
  if (this != &other) {
    free();
    elements = other.elements;
    first_free = other.first_free;
    cap = other.cap;
    other.elements = other.first_free = other.cap = nullptr;
  }
  return *this;
}

MyString::~MyString() {
  free();
  std::cout << "MyString destructor is called" << std::endl;
}

std::pair<char*, char*> MyString::alloc_n_copy(const char* begin,
                                               const char* end) {
  auto new_space = alloc.allocate(end - begin);
  return {new_space, std::uninitialized_copy(begin, end, new_space)};
}

void MyString::free() {
  if (elements) {
    std::for_each(elements, first_free, [](const char& c) {
      std::allocator_traits<std::allocator<char>>::destroy(alloc, &c);
    });
    alloc.deallocate(elements, cap - elements);
  }
}

void MyString::reallocate() {
  const auto sz = size() ? 2 * size() : 1;
  auto new_space = alloc.allocate(sz);
  auto last = std::uninitialized_copy(elements, first_free, new_space);
  free();
  elements = new_space;
  first_free = cap = last;
}

void MyString::push_back(const char& c) {
  check_n_alloc();
  std::allocator_traits<std::allocator<char>>::construct(alloc, first_free++,
                                                         c);
}
