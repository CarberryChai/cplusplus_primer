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

## 15.13

> given the following classes, explain each print function:
>
> ```c++
> class base {
>   public:
>   	string name() {return basename;}
>   	virtual void print(ostream &os) {os << basename;}
>   private:
>   	string basename;
> };
> class derived : public base {
>   public:
>   	void print(ostream &os) {
>       print(os);
>       os<<" " <<i;
>     }
>   private:
>   	int i;
> };
> ```
>
> 

Yes 

> If a derived virtual function that intended to call its base-class version omits the scope operator, the call will be resolved at run time as a call to the derived version itself, resulting in an infinite recursion.

Fixed:

```c++
class derived : public base {
  public:
  	void print(ostream &os) {
      base::print(os);
      os << " " << i;
    }
  private:
  	int i;
};
```

## 15.14

> Given the classes from the previous exercise and the following objects, determine which function is called at run time;

```c++
base bobj;
base *bp1 = &bobj;
base &br1 = bobj;
derived dobj;
base *bp2 = &dobj;
base &br2 = dobj;
// 
bobj.print(); // compile 
dobj.print(); // compile
bp1->name(); // compile
bp2->name(); // compile
br1.print(); // compile
br2.print(); // run time
```

## 15.15、15.16、15.17

> - Define your own versions of `Disc_quote` and `Bulk_quote`.
> - Rewrite the class representing a limited discount strategy, which you wrote for the exercises int 15.2.2, to inherit from `Disc_quote`.
> - Try to define an object of type `Disc_quote` and see what errors you get from the compiler.

[code](./exercise15_15.cpp)

```c++
int main() {
   Disc_quote d;
}
```

errors from the compiler

![](https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/m891ty-qJVuLP.png)

## 15.18

> Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are ilegal aren't allowed:

[code](./exercise15_18.cpp)

> Whether the derived-to-base conversion is accessible depends on which code is trying to use the conversion and may depend on the access specifier used in the derived class derivation. Assuming D ingerits from B :
>
> - User code may use the derived-to-base conversion only if D inherits **publicly** from B. User code may not use the conversion if D inherits from B using either `protected` or `private`.

## 15.19

> Assume that each of the classes from page 612 and page 613 has a member function of the form:
>
> ```c++
> void memfcn(Base &b) {
>   b = *this;
> }
> ```
>
> For each class, determine whether this function would be legal.

for `Derived_from_Private`, the `memfcn` member function is illegal.

> Assuming D inherits from B
>
> Member functions and friends of classes derived from D may use the derived-to-base conversion if D inherits from B using either `public` or `protected`.such code may not use the conversion if D inherits privately from B.

## 15.21 or 15.22

> - Choose one of the following general abstractions containing a family of types (or choose one of your own). Organize the types into a inheritance hierarchy:
>
>   (a) Graphical file formats (such as gif, tiff, jpeg, bmp)
>
>   (b) Geometric primitives (such as box, circle, sphere, cone)
>
>   (c) C++ language types (such as class, function, member function)
>
> - For the class you chose in the previous exercise, identify some of the likely virtual functions as well as public and ptotected members.

[code](./exercise15_22.cpp)

