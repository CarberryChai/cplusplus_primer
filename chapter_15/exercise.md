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