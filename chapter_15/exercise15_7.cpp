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

class Limit_Quote : public Quote {
 public:
  Limit_Quote() = default;
  Limit_Quote(const std::string &book, double p, size_t max_q, double disc)
      : Quote(book, p), max_qty(max_q), discount(disc) {}
  double net_price(size_t n) const override;

 private:
  size_t max_qty = 0;
  double discount = 0.0;
};

double Limit_Quote::net_price(size_t n) const {
  if (n <= max_qty) return n * price * (1 - discount);
  return (n - max_qty) * price + max_qty * price * (1 - discount);
}

double print_total(std::ostream &os, const Quote &book, size_t n) {
  auto ret = book.net_price(n);
  os << "ISBN: " << book.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Limit_Quote book("c++ primer", 62, 50, 0.1);
  print_total(std::cout, book, 100);
}