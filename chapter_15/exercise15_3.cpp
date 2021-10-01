//
// Created by 柴长林 on 2021/10/1.
//

#include <iostream>
#include <string>
#include <utility>

class Quote {
 public:
  Quote() = default;
  Quote(std::string book, double p) : price(p), bookNo(std::move(book)) {}
  std::string isbn() const { return bookNo; }
  virtual double net_price(size_t n) const { return n * price; }
  virtual ~Quote() = default;

 protected:
  double price = 0.0;

 private:
  std::string bookNo;
};

double print_total(std::ostream &os, const Quote &book, size_t n) {
  auto ret = book.net_price(n);
  os << "ISBN: " << book.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Quote book("c++ primer", 50);
  print_total(std::cout, book, 5);
}