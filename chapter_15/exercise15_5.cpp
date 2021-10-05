//
// Created by 柴长林 on 2021/10/5.
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

class Bulk_Quote : public Quote {
 public:
  Bulk_Quote() = default;
  Bulk_Quote(const std::string &book, double p, size_t q, double disc)
      : Quote(book, p), min_qty(q), discount(disc) {}
  double net_price(size_t) const override;

 private:
  size_t min_qty = 0;
  double discount = 0.0;
};

double Bulk_Quote::net_price(size_t n) const {
  if (n >= min_qty) return n * price * (1 - discount);
  return n * price;
}

double print_total(std::ostream &os, const Quote &book, size_t n) {
  auto ret = book.net_price(n);
  os << "ISBN: " << book.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Bulk_Quote book("c++ primer", 63, 50, 0.12);
  print_total(std::cout, book, 60);
  Quote quote("english learing", 34);
  print_total(std::cout, quote, 40);
};