//
// Created by 柴长林 on 2021/3/2.
//

#ifndef CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_24_H_
#define CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_24_H_
class Screen {
 public:
  using Pos = std::string::size_type;
  Screen() = default;
  Screen(Pos ht, Pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  Screen(Pos ht, Pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

 private:
  Pos cursor = 0, height = 0, width = 0;
  std::string contents;
};
#endif  // CPLUSPLUS_PRIMER_CHAPTER_7_EXERCISE7_24_H_
