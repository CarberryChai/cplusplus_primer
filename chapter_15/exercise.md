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

