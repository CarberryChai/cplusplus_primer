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

## 12.16

> compilers don't always give easy-to-understand error messages if we attempt to copy or assign a unique_ptr. Write a program that contains these errors to see how your compiler diagnoses them.

```c++
std::unique_ptr<int> p1(new int(12));
std::unique_ptr<int> p2(p1); // error: copy constructor is implicitly deleted because 'unique_ptr<int>' has a user-declared move constructor
std::unique_ptr<int> p3;
p3 = p1; // error: copy assignment operator is implicitly deleted because 'unique_ptr<int>' has a user-declared move constructor
std::cout << *p2 << std::endl;
```

## 12.18

> Why doesn't shared_ptr have a release member ?

`shared_ptr` can't give away ownership unless it's unique() because the other copy will still destory the object.

## 12.19

> Define your own version of `StrBlobPtr` and update your `StrBlob` class with the appropriate friend declaration and begin and end members.

[StrBlobPtr.h](./StrBlobPtr.h)

[StrBlobPtr.cpp](./StrBlobPtr.cpp)

## 12.20

> Write a program that reads an input file a line at a time into a `StrBlob` and use a `StrBlobPtr` to prit each element int rhat `StrBlob`.

[code](./exercise12_20.cpp)

## 12.21

> We could have written `StrBlobPtr`'s deref member as follows:
>
> ```c++
> std::string& deref() const {
>   return (*check(curr, "dereference past end"))[curr];
> }
> ```
>
> Which ersion do you think is better and why?

The original one is better, because it's more readable.

## 12.25

> Given the following new expression, how would you delete pa ?

```c++
int *pa = new int[10];
delete [] pa;
```

## 12.26

> Rewrite the program on page 481 using an allocator.

[code](./exercise12_26.cpp)

## 12.30

> Define your own versions of the TextQuery and QueryResult classes and execute the runQueries function.

[TextQuery.h](./TextQuery.h)

[TextQuery.cpp](./TextQuery.cpp)

[QueryResult.h](./QueryResult.h)

[QueryResult.cpp](./QueryResult.cpp)

## 12.32

> Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a vector<string> to hold the input file.

[TextQueryStrBlob.h](./TextQueryStrBlob.h)

[TextQueryStrBlob.cpp](./TextQueryStrBlob.cpp)

[QueryResultStrBlob.h](./QueryResultStrBlob.h)

[QueryResultStrBlob.cpp](./QueryResultStrBlob.cpp)

