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

**Member functions access the object on which they were called through an extra, implicit parameter named `this`.**

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

Classes control object initialization by defining one or more special member functions known as **constructors**. **The job of a constructor is to initialize the data members of a class object. A constructor is run whenever an object of a class type is created.**

Constructors have the same name as the class.  have a (possibly empty) parameter list and a (possibly empty) function body. A class can have multiple constructors. Like any other overloaded function (§ 6.4, p. 230), the con- structors must differ from each other in the number or types of their parameters.

## The Synthesized Default Constructor

```c++
Sales_data total;
Sales_data trans;
```

The question naturally arises: How are `total` and `trans` initialized?

We did not supply an initializer for these objects, so we know that they are **default initialized** (§ 2.2.1, p. 43). Classes control default initialization by defining a special constructor, known as the **default constructor**. **The default constructor is**
**one that takes no arguments.**

As we’ll, see the default constructor is special in various ways, **one of which is that if our class does not explicitly define any constructors, the compiler will implicitly define the default constructor for us**

For most classes, this synthesized constructor initializes each data mem- ber of the class as follows:

- If there is an in-class initializer (§ 2.6.1, p. 73), use it to initialize the member.
- Otherwise, default-initialize (§ 2.2.1, p. 43) the member.

Because Sales_data provides initializers for units_sold and revenue, the synthesized default constructor uses those values to initialize those members. It default initializes bookNo to the empty string.

**The most common reason that a class must define its own default constructor is that the compiler generates the default for us only if we do not define any other constructors for the class.**

 **The compiler generates a default constructor automatically only if a class declares no constructors.**

A second reason to define the default constructor is that for some classes, the synthesized default constructor does the wrong thing. **Remember that objects of built-in or compound type (such as arrays and pointers) that are defined inside a block have undefined value when they are default initialized (§ 2.2.1, p. 43). The same rule applies to members of built-in type that are default initialized.** **Therefore, classes that have members of built-in or compound type should ordinarily either initialize those members inside the class or define their own version of the default constructor. Otherwise, users could create objects with members that have undefined value.**

## What = default Means

We’ll start by explaining the default constructor:

```c++
Sales_data() = default;
```

First, note that this constructor defines the default constructor because it takes no arguments. 

Under the new standard, if we want the default behavior, we can ask the com- piler to generate the constructor for us by writing `= default` after the parameter list.

## Constructor Initializer List

```c++
Sales_data(const std::string& s): bookNo(s) {}
Sales_data(const std::string& s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n) {}
```

The new parts in these definitions are the colon and the code between it and the curly braces that define the (empty) function bodies. This new part is a **constructor initializer list**, which specifies initial values for one or more data members of the object being created. The constructor initializer is a list of member names, each of which is followed by that member’s initial value in **parentheses (or inside curly braces).** Multiple member initializations are separated by commas.

## Using the class or struct Keyword

A class may define members before the first access specifier. Access to such members depends on how the class is defined. **If we use the struct keyword, the members defined before the first access specifier are `public`; if we use class, then the members are `private`.**

As a matter of programming style, when we define a class intending for all of its members to be public, we use struct. If we intend to have private members, then we use class.

 **The only difference between using class and using struct to define a class is the default access level.**

## Friends

Now that the data members of `Sales_data` are `private`, our `read`, `print`, and `add` functions will **no longer compile**. The problem is that although these functions are part of the Sales_data interface, they are not members of the class.

**A class can allow another class or function to access its nonpublic members by making that class or function a friend.**

**A friend declaration only specifies access. It is not a general declaration of the function.**

## Returning *this from a const Member Function

Next, we’ll add an operation, which we’ll name display, to print the contents of the Screen.

Logically, displaying a Screen doesn’t change the object, so we should make display a const member. If display is a const member, then `this` is a pointer to const and `*this` is a const object. Hence, the return type of display must be` const Sales_data&.` However, if display returns a reference to const, we won’t be able to embed display into a series of actions:

```c++
Screen myScreen;
myScreen.display(cout).set('*'); // if display returns a const reference, the call to set is an error
```

**The problem is that the const version of display returns a reference to const and we cannot call set on a const object.**

