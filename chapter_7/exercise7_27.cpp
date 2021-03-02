//
// Created by 柴长林 on 2021/3/2.
//
#include <iostream>
class Screen {
 public:
  using Pos = std::string::size_type;
  Screen() = default;
  Screen(Pos ht, Pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  Screen(Pos ht, Pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen& set(char c) {
    contents[cursor] = c;
    return *this;
  }
  Screen& set(Pos r, Pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
  }
  Screen& move(Pos r, Pos c) {
    Pos row = r * width;
    cursor = row + c;
    return *this;
  }
  Screen& display(std::ostream& out) {
    out << contents;
    return *this;
  }
  [[nodiscard]] const Screen& display(std::ostream& out) const {
    out << contents;
    return *this;
  }

 private:
  Pos cursor = 0, height = 0, width = 0;
  std::string contents;
};

int main() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(std::cout);
  std::cout << "\n";
  myScreen.display(std::cout);
  std::cout << "\n";
}