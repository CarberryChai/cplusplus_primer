# Classes

**The fundamental ideas behind classes are data abstraction and encapsulation.**

**Data abstraction is a programming (and design) technique that relies on the separation of interface and implementation.**

**A class that uses data abstraction and encapsulation defines an abstract data type.**

## Defining the Revised Sales_data Class

We define (§ 6.1, p. 202) and declare (§ 6.1.2, p. 206) member functions similarly to ordinary functions. **Member functions must be declared inside the class. Member functions may be defined inside the class itself or outside the class body.** Non- member functions that are part of the interface, such as **add**, **read**, and **print**, are declared and defined outside the class.

With this knowledge, we’re ready to write our revised version of Sales_data:

```c++
struct Sales_data {
  std::string isbn() const {return bookNo;}
  Sales_data& combine(const Sale_data&);
  double avg_price() const;
  
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
}
// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```

**Functions defined in the class are implicitly inline**.

## Introducing this

Let’s look again at a call to the isbn member function:

```c++
total.isbn();
```

When `isbn` refers to members of `Sales_data` (e.g., `bookNo`), it is referring implicitly to the members of the object on which the function was called. In this call, when `isbn` returns `bookNo`, it is implicitly returning `total.bookNo`.

**Member functions access the object on which they were called through an ex- tra, implicit parameter named `this`.**

**When we call a member function, `this` is initialized with the address of the object on which the function was invoked.** For example, when we call `total.isbn()`.

the compiler passes the address of total to the implicit this parameter in isbn. It is as if the compiler rewrites this call as

```c++
// pseudo-code illustration of how a call to a member function is translated
Sales_data::isbn(&total);
```

which calls the `isbn` member of `Sales_data` passing the address of `total`.

## Introducing const Member Functions

**The other important part about the `isbn` function is the keyword `const` that follows the parameter list. The purpose of that `const` is to modify the type of the implicit `this` pointer.**

By default, **the type of this is a const pointer to the nonconst version of the class type**.

**A `const` following the parameter list indicates that `this` is a pointer to `const`. Member functions that use `const` in this way are const member functions.**

**Objects that are const, and references or pointers to const objects, may call only const member functions.**

##  Constructors

