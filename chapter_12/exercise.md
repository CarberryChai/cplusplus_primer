# chapter 12 Dynamic Memory

## 12.1

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

## 12.2

> Write your own version of the StrBlob class including the const versions of front and back.

[StrBlob.h](./StrBlob.h)

[StrBlob.cpp](./StrBlob.cpp)

## 12.3

> Does this class need `const` versions of `push_back` and `pop_back` ? If so, add them. If not, why are't they needed ?

不加，相信请看[👉](https://www.douban.com/group/topic/61573279/)

## 12.4

> In our check function we didn't check whether i was greater than zero. Why is it okay to omit that check;

The type of i is `std::vector<std::string>::size_type`, which is an unsigned integer.

## 12.5

> We did not make the constructor that takes an initializer_list explicit. Discuss the pros and cons of this design choice.

Keywork `explicit` prevents automatic conversion form an `initializer_list` to `StrBlob`. This design choice wuld easy to use but hard to debug.

## 12.6

> Write a function that returns a dynamically allocated vector of ints. Pass that vector to another function that reads the standard input to give values to the elements. Pass the vector to another function to print the values that were read. Remember to delete the vector at the appropriate time.

[code](./exercise12_6.cpp)

## 12.7

> Redo the previous exercise, this time using shared_ptr.

[code](./exercise12_7.cpp)

## 12.8

> Explain what if anything is wrong with the following function.

```c++
bool b() {
  int* p = new int;
  // ...
  return p;
}
```

The pointer p wil convert to bool, which means the dynamically allocated memory has no chance to be freed. As a result, memory leakage will occur.

## 12.9

> Explain what happens in the following code:

```c++
int *q = new int(42), *r = new int(100);
r = q;
// memory leakage happens. Because after r = q was executed, no pointer points to r had pointed to. It implies that no chance to free the memory
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
// It's safe. Because after r2 = q2 was executed, the r2 counter goes to zero, which automatically frees the object that it manages.
```

## 12.10

> Explain whether the following call to the process function defined on page 464 is correct. If not, how would you correct the call ?

```c++
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

Yes, it's correct.

## 12.11

> What would happen if we called process as follows ?

```c++
process(shared_ptr<int>(p.get()));
```

Both `p` and the argument `ptr` of process point to the same memory. Each has a reference count of 1. When the function process   is called, the `ptr` is destoryed. Destorying `ptr` frees the memory to which `p` point. That makes `p` intto a dangling point, meaning that what happens when we attempt to use `p` is undefined. Moreover, when `p` is destoryed , the pointer to that memory will be deleted a second time.

## 12.12

> Using the declarations of p and sp explain each of the following calls to process. if the call is legal, explain what it does. If the call if illegal, explain why:

```c++
auto p = new int();
auto sp = make_shared<int>();
process(sp); // ok
process(new int()); // illegal, can convert the int* to shared_ptr<int>
process(p); // illegal
process(shared_ptr<int>(p)); // ok, but it's a bad practice.
```

## 12.13

> What happens if we execute the following code ?

```c++
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

Error, double free the same memory

