

# Chapter Six Exercise

## 6.1

> What is the difference between a parameter and an argument?

Arguments are the initializers for a function’s parameters. 

**Parameters**: Local variable declared inside the function parameter list. they are initialized by the **arguments** provided in the each function call.

**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

## 6.2

> Indicate which of the following functions are in error and why. Suggest how you might correct the problems.

```c++
string f() {
  string s;
  return s;
} // the return type should be string, not int
```

------

```c++
void f2(int i) {
  // ...
} // f2 needs the return type
```

------

```c++
int calc(int v1, int v2) {
  // .. 
} // the two parameters cannot have the same name
```

------

```c++
double square(double x) {
  return x * x;
} // function body needs braces
```

## 6.3

> Write and test your own version of fact.

[code](./exercise6_3.cpp)

## 6.4

> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.

[code](./exercise6_4.cpp)

## 6.5

> Write a function to return the absolute value of its argument.

```c++
int abs(int x) {
  return x >= 0 ? x : -x;
}
```

## 6.6

> Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.

**local variable**: Variables defined inside a **block**;

**parameter**: **Local variables** declared inside the **function parameter list**

**local static variable**: **local static variable（object）** is initialized before the first time execution passes through the object’s definition.**Local statics** are not destroyed when a function ends; they are **destroyed when the program terminates.**

## 6.7

> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

[code](./exercise6_7.cpp)

## 6.8

> Write a header file named Chapter6.h that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).

[Chapter6.h](./Chapter6.h)

## 6.9

> Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

[fact.cc](./fact.ccp)   [factMain.cpp](./factMain.cpp)

## 6.10

> Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.

[code](./exercise6_10.cpp)

## 6.11

> Write and test your own version of reset that takes a reference.

[code](./exercise6_11.cpp)

## 6.12

> Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use refer- ences instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

[code](./exercise6_12.cpp)

The reference version is easier to use.

## 6.13

> Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&).

`void f(T)` pass the argument by value

`void f(T&)`  pass the argument by reference

## 6.14

> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

a parameter should be a reference type:

```c++
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
```

a parameter should not be a reference:

```c++
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```

## 6.15

> Explain the rationale for the type of each of find_char’s parameters In particular, why is s a reference to const but occurs is a plain reference? Why are these parameters references, but the char parameter c is not? What would happen if we made s a plain reference? What if we made occurs a reference to const?

why is s a reference to const but occurs is a plain reference?

我们的意图是在字符串`s`中查找给定字符，并没有打算修改字符串`s`, 因此最好把`s`设置为 a reference to const. 至于`occurs`是一个普通reference，因为我们打算修改它的值。

 Why are these parameters references, but the char parameter c is not?

也可以设置为reference，但没必要，`char`类型所占空间很小，copy的代价很小

What would happen if we made s a plain reference? What if we made occurs a reference to const?

没变化，因为我们并没有打算修改字符串`s`，最好还是设置成 a reference to const;

如果我们把`occurs`设置为a reference to const，`occurs = 0;` would be an error;

