//
// Created by 柴长林 on 2021/3/4.
//
#include <iostream>

class Debug {
 public:
  constexpr explicit Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
  [[nodiscard]] constexpr bool any() const { return hw || io || other; }
  void set_hw(bool b) { hw = b; }
  void set_io(bool b) { io = b; }
  void set_other(bool b) { other = b; }

 private:
  bool hw;
  bool io;
  bool other;
};

int main() {
  constexpr Debug io_debug(false, true, false);
  if (io_debug.any()) {
    std::cout << "io error occurred" << std::endl;
  }
}