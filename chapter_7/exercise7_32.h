//
// Created by 柴长林 on 2021/3/2.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_32_H_
#define CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_32_H_
#include <iostream>
#include <vector>
class Screen;
using std::vector;
class Window_mgr {
 public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);

 private:
  vector<Screen> screens{screen(24, 80, ' ')};
};
class Screen {
 public:
  using Pos = std::string::size_type;
  friend void Window_mgr::clear(ScreenIndex);
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
    do_display(out);
    return *this;
  }
  [[nodiscard]] const Screen& display(std::ostream& out) const {
    do_display(out);
    return *this;
  }

 private:
  Pos cursor = 0, height = 0, width = 0;
  std::string contents;
  void do_display(std::ostream& out) const { out << contents; }
};
inline void Window_mgr::clear(ScreenIndex i) {
  if (i >= screens.size()) return;
  Screen& s = screens[i];
  s.contents = std::string(width * height, ' ');
}
#endif  // CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_32_H_
