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