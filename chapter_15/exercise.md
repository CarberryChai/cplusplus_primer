# Object-Oriented Programming

## 15.1

> What is a virtual member ?

> The base class defines as **virtual** those functions it expects its derived classes to override.
>
> When we call a virtual function *through a pointer or reference* , the call will be dynamically bound.
>
> A base class specifies that a member function should be dynamically bound by preceding its declaration with the keyword `virtual`.

## 15.2

> How does the `protected` access specifier differ from `private` ?

A `protected` member in base class can be access  by its derived class, while a `private` member can't.

## 15.3

> define your own versions of the `Quote` class and the `print_total` function

[code](./exercise15_3.cpp)

## 15.4

> which of the following declarations , if any, are incorrect? Explain why.
>
> ```c++
> class Base {};
> ```
>
> 

(a) `class Derived : public Derived {}` its incorrect. 

> One implication of this rule is that it is impossible to derive a class from itself.

(b) `class Derived : private Base {}` its not only a declaration, but also a definition.

(c) `class Derived : public Base;` its incorrect.

> the declaration contains the class name but does not include its derivation list

## 15.5、15.6

> - define your own version of the `Bulk_quote` class.
> - Test your `print_total` function from the exercises in 15.2.1 by passing both `Quote` and `Bulk_Quote` objects to that function.

[code](./exercise15_5.cpp)

## 15.7

> Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. if the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.

[code](./exercise15_7.cpp)

## 15.8

> define static type and dynamic type.

> The **static type** of an expression is always known at **compile** time —— it's the type with which a variable is declared or that an expression yields.
>
> The **dynamic type** is the type of the object in memory that the variable or expression represents. the dynamic type may not be known until run time.
>
> The dynamic type of an expression that is neither a reference nor a pointer is always the same as that expression's static type.

## 15.9

> when is it possible for an expression's static type to differ from its dynamic type ? give three examples in which the static and dynamic type differ.

> The dynamic type of an expression that is neither a reference nor a pointer is always the same as that expression's static type.

```c++
class Base {};
class Derived : public Base {};
Derived d;
Base *bp = &d;
Base &br = d;
Derived *dp = &d;
Base *bp2 = dp;
```

## 15.10

> recalling the discussion from p.311, explain how the program on page 317 that passed an `ifstream` to the `Sales_data` `read` function works.

The type `ifstream` inherits from `istream`. Thus, we can use objects of type `ifstream` as if they were `istream` objects. The parameter of `read` function is a reference to base type `istream`, the automatic derived-to-base conversion applies when we pass  

 a derived type `ifstream` to that function. inside `read` function, we can use the `istream` subpart in the `ifstream` object through the reference.

## 15.11

> Add a virtual `debug` function to your `Quote` class hierarchy that displays the data members of the respective classes.

[code](./exercise15_7.cpp)