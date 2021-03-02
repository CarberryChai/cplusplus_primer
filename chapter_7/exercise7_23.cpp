//
// Created by 柴长林 on 2021/3/1.
//
#include <iostream>
class Screen {
 public:
  using Pos = std::string::size_type;
  Screen() = default;
  Screen(Pos ht, Pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  [[nodiscard]] char get() const { return contents[cursor]; }
  [[nodiscard]] char get(Pos r, Pos c) const;
  Screen& move(Pos r, Pos c);

 private:
  Pos cursor = 0, height = 0, width = 0;
  std::string contents;
};

inline char Screen::get(Pos r, Pos c) const {
  Pos row = r * width;
  return contents[row + c];
}
inline Screen& Screen::move(Pos r, Pos c) {
  Pos row = r * width;
  cursor = row + c;
  return *this;
}