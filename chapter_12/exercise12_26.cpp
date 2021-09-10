//
// Created by 柴长林 on 2021/9/10.
//
#include <iostream>
#include <memory>
// since the members functions construct and destroy of allocator are
// deprecated, so we use the same name static member functions of
// allocator_traits
void allocate_and_deallocate(int n) {
  std::allocator<std::string> allocator;
  auto p = allocator.allocate(n);
  auto q = p;
  std::string s;
  while (std::cin >> s && q != p + n) {
    std::allocator_traits<std::allocator<std::string>>::construct(allocator,
                                                                  q++, s);
  }
  while (q != p) {
    std::cout << *--q << std::endl;
    std::allocator_traits<std::allocator<std::string>>::destroy(allocator, q);
  }
  allocator.deallocate(p, n);
}
int main() { allocate_and_deallocate(3); }