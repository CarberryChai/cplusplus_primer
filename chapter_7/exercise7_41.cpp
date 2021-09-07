//
// Created by 柴长林 on 2021/3/3.
//
#include <iostream>

class Sales_data {
  friend std::istream& read(std::istream& input, Sales_data& item);

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

 public:
  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {
    std::cout << "three parameters constructor" << std::endl;
  }
  Sales_data() : Sales_data("", 0, 0) {
    std::cout << "default constructor" << std::endl;
  }
  explicit Sales_data(const std::string& s) : Sales_data(s, 0, 0) {
    std::cout << "single string constructor" << std::endl;
  }
  explicit Sales_data(std::istream& is) : Sales_data() {
    std::cout << "single istream constructor" << std::endl;
    read(is, *this);
  }
  [[nodiscard]] std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data& rhs);
  [[nodiscard]] double avg_price() const;
};

int main() {
  Sales_data s1;
  Sales_data s2{"677-2788328-h", 5, 10};
  Sales_data s3{"266637-288-b"};
  // Sales_data s4(std::cin);
}