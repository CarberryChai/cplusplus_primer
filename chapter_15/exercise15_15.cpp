//
// Created by 柴长林 on 2021/10/21.
//
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
  double price{};

 private:
  std::string bookNo;
};

class Disc_quote : public Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double p, size_t qty, double disc)
      : Quote(book, p), quantity(qty), discount(disc) {}
  double net_price(size_t n) const override = 0;

 protected:
  size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, size_t qty, double disc)
      : Disc_quote(book, p, qty, disc) {}
  double net_price(size_t n) const override;
};

double Bulk_quote::net_price(size_t n) const {
  if (n > quantity) return n * price * (1 - discount);
  return n * price;
}

class Limit_quote : public Disc_quote {
 public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double p, size_t max_qty, double disc)
      : Disc_quote(book, p, max_qty, disc) {}
  double net_price(size_t n) const override;
};

double Limit_quote::net_price(size_t n) const {
  if (n >= quantity)
    return quantity * price * (1 - discount) + (n - quantity) * price;
  return n * price * (1 - discount);
}

int main() {
  Disc_quote d;
}