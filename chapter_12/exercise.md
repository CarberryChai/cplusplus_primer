# chapter 12 Dynamic Memory

# 12.1

> How many elements do b1 and b2 have at the end of this code?

```c++
StrBlob b1;
{
  StrBlob b2 = {"a", "an", "the"};
  b1 = b2;
  b2.push_back("about");
}
```

```c++
std::cout<< b1.size(); // 4
```

# 12.2

> Write your own version of the StrBlob class including the const versions of front and back.

[StrBlob.h](./StrBlob.h)

[StrBlob.cpp](./StrBlob.cpp)

# 12.3

> Does this class need `const` versions of `push_back` and `pop_back` ? If so, add them. If not, why are't they needed ?

不加，相信请看[👉](https://www.douban.com/group/topic/61573279/)

# 12.4

> In our check function we didn't check whether i was greater than zero. Why is it okay to omit that check;

The type of i is `std::vector<std::string>::size_type`, which is an unsigned integer.

# 12.5

> We did not make the constructor that takes an initializer_list explicit. Discuss the pros and cons of this design choice.

Keywork `explicit` prevents automatic conversion form an `initializer_list` to `StrBlob`. This design choice wuld easy to use but hard to debug.