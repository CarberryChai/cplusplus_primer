# Chapter Seven Exercise

## 7.1

> Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).

The same as the exercise 2.41, see [code](exercise2_42_3.cpp)

## 7.2

> Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).

[Sales_data.h](../include/Sales_data.h)  [Sales_data](Sales_data.cpp)

## 7.3

> Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.

[code7.3](./exercise7_3.cpp)

## 7.4 and 7.5

> - Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.
> - Provide operations in your Person class to return the name and ad- dress. Should these functions be const? Explain your choice.

[Person](../include/Person.h)

## 7.6

> Define your own versions of the add, read, and print functions.

 [Sales_data](Sales_data.cpp)

## 7.7

> Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.

[code7.7](./exercise7.7.cpp)

## 7.8

> Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?

Defining `Sales_data` parameter as a plain reference in read member function is to modify the value of the object member.

Defining its parameter as a reference to const is that we are not going to modify that object.

## 7.9

> Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).

[Person](./Person.cpp)

## 7.10

> What does the condition in the following if statement do?

It would like that:

```c++
cin >> data1 >> data2;
if(cin)
```

## 7.11

> Add constructors to your Sales_data class and write a program to use each of the constructors.

 [Sales_data](Sales_data.cpp)  [code7.11](./exercise7_11.cpp)

## 7.12

> Move the definition of the Sales_data constructor that takes an istream into the body of the Sales_data class.

[Sales_data.h](../include/Sales_data.h)

## 7.13

> Rewrite the program from page 255 to use the istream constructor

[code7.13](./exercise7_13.cpp)

## 7.14

> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

```c++
Sales_data():bookNo(), units_sold(0), revenue(0.0) {}
```

## 7.15

> Add appropriate constructors to your Person class.

[Person.h](../include/Person.h)

## 7.16

> What, if any, are the constraints on where and how often an access spec- ifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?

A class may contain zero or more access specifiers, and there are no restrictions on how often an access specifier may appear. Each access specifier specifies the access level of the succeeding members.

The **public** members define the interface to the class.

The **private** sections encapsulate (i.e., hide) the implementation.

## 7.17

> What, if any, are the differences between using class or struct?

If we use the struct keyword, the members defined before the first access specifier are **public**; if we use class, then the members are **private**.

## 7.18

> What is encapsulation? Why is it useful?

The interface of a class consists of the operations that users of the class can execute. The implementation includes the class’ data members, the bodies of the functions that constitute the interface, and any functions needed to define the class that are not intended for general use.

Encapsulation enforces the separation of a class’ interface and implementation. A class that is encapsulated hides its implementation—users of the class can use the interface but have no access to the implementation.

A class that uses data abstraction and encapsulation defines an abstract data type. In an abstract data type, the class designer worries about how the class is implemented. Programmers who use the class need not know how the type works. They can instead think abstractly about what the type does.

## 7.19

> Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.

```c++
class Person {
private:
  std::string name, address;
public:
  const std::string& get_name() const { return name; }
  const std::string& get_address() const { return address; }

  Person() = default;
  Person(const std::string& name, const std::string& address)
      : name(name), address(address) {}
  Person(const std::string& name) : name(name) {}
  Person(std::istream& is);
}
```

## 7.20

> When are friends useful? Discuss the pros and cons of using friends.

[see more about friend](https://isocpp.org/wiki/faq/friends#friends-and-encap)

## 7.21

> Update your Sales_data class to hide its implementation. The pro- grams you’ve written to use Sales_data operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

[Sales_data.h](../include/Sales_data.h)

## 7.22

> Update your Person class to hide its implementation.

[Person.h](../include/Person.h)

## 7.23

> Write your own version of the Screen class.

[code7.23](./exercise7_23.cpp)

## 7.24

> Give your Screen class three constructors: a default constructor; a con- structor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

[code7.25](./exercise7_24.h)

## 7.25

> Exercise 7.25: Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?

It can rely on;

> Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have vector or string members. When we copy or assign an object that has a vector member, the vector class takes care of copy- ing or assigning the elements in that member. When the object is destroyed, the vector member is destroyed, which in turn destroys the elements in the vector. Similarly for strings.

## 7.26

> Define Sales_data::avg_price as an inline function.

[code7.26](./Sales_data.cpp)

## 7.27

> Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:

[code7.27](./exercise7_27.cpp)

## 7.28

> What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?

`Screen`:

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/FjNfci-O5535p.png" style="zoom:50%;" />

`Screen&`:

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/UYG2sC-WZ3bOe.png" style="zoom:50%;" />

## 7.30

> It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.

pros

- More explicit

- Less scope for misreading

- Can use the member function parameter which name is same as the member name.

  ```c++
  void setName(const std::sting name) {
    this->name = name;
  }
  ```

cons

- More to read

- Sometimes redundant

  ```c++
  std::string getName() const {
    return this->name; // unnecessary
  }
  ```

  

## 7.31

> Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.

```c++
class Y;
class X {
  private:
  	Y *_y = nullptr;
}
class Y {
  private:
  	X _x;
}
```

## 7.32

> Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.

[code7.32](./exercise7_32.h)

## 7.33

> What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.

```c++
pos Screen::size() const {
  return height * width;
}
```

Error: unknow type name 'pos'

Fixed:

```c++
Screen::pos Screen::size() const {
  return height * width;
}
```

## 7.34

> What would happen if we put the typedef of pos in the Screen class on page 285 as the last line in the class?

Error: unknow type name 'pos'

## 7.35

> Explain the following code, indicating which definition of Type or initVal is used for each use of those names. Say how you would fix any errors.

```c++
typedef string Type;
Type initVal; // string
class Exercise {
  public:
  	typedef double Type;
  	Type setVal(Type); // double double
  	Type initVal(); // double
  private:
  	int val;
};
Type Exercise::setVal(Type parm) { // string double
  val = parm + initVal(); // Exercise::initVal()
  return val;
}
```

Fixed:

```c++
Exercise::Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}
```

The member function `Exercise::initVal` must be defined 

## 7.36

> The following initializer is in error. Identify and fix the problem.

```c++
struct X {
  X (int i, int j): rem(i % j), base(i) {}
  int rem, base;
}
```

## 7.37

> Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:

```c++
Sales_data first_item(cin); // Sales_data(std::istream& is) its value depend on your input

int main() {
  Sales_data next; // Sales_data(std::string s = ""):bookNo(s) {}  bookNo "", units_sold 0, revenue 0
  Sales_data last("9-999-99999-9");
  // Sales_data(std::string s = ""):bookNo(s) {}  bookNo "9-999-99999-9", units_sold 0, revenue 0
}
```

## 7.38

> We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.

```c++
Sales_data(std::istream& is = std::cin) {
  read(is, *this);
}
```

## 7.39

> Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?

Illegal; the call of overloaded `Sales_data()` is **ambiguous**

## 7.40

> Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.
>
> (a) Book (b) Date (c) Employee (d) Vehicle (e) Object (f) Tree

I choose Employee

```c++
class Employee {
  public:
  	Employee() = default;
  	Employee(const string& i, const string& n, const string& d, double s):id(i), name(n), department(d), salary(s) {}
  	Employee(std::istream& is){
      is >> id >> name >> department >> salary;
    }
  private:
  	string id, name, department;
  	double salary;
}
```

## 7.41

> Rewrite your own version of the Sales_data class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

[code7.41](./exercise7.41.cpp)

## 7.42

> For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating con- structor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

```c++
class Employee {
  public:
  	Employee(const string& i, const string& n, const string& d, double s):id(i), name(n), department(d), salary(s) {}
  	Employee():Employee("", "", "", 0) {}
  	Employee(std::istream& is):Employee() {
      is >> id >> name >> department >> salary;
    }
  private:
  	string id, name, department;
  	double salary;
}
```

## 7.43

> Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.

```c++
struct NoDefault {
  NoDefault(int i) {}
};

class C {
  public:
  	C() = default;
  private:
  	NoDefault _m;
}
```

## 7.44

> Is the following declaration legal? If not, why not?

```c++
vector<NoDefault> vec(10);
```

Illegal; `vector<NoDefault>` will initialize ten elements of value initialization, but class NoDefault has no default initialization.

## 7.45

> What if we defined the vector in the previous execercise to hold ob- jects of type C?

Illegal; C has a data member which is NoDefault type, so initializing C will get error

## 7.46

> Which, if any, of the following statements are untrue? Why?

- (a) A class must provide at least one constructor. (**Untrue**; "the compiler-generated constructor is known as the synthesized  default constructor.")
- (b) A default constructor is a constructor with an empty parameter list. (**Untrue**, A default constructor is a constructor that is used if no initializer is supplied. What's more, A constructor that supplies default arguments for all its parameters also defines constructor)
- (c) if there are no meaningful default values for a class, the class should not provide a default constructor. (**Untrue**, the class should provide)
- (d) if a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type. (**Untrue**, only if our class does not explicitly define any constructors, the compiler will implicitly define the default constructor for us)

## 7.47

> Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?

Whether the conversion of a string to Sales_data is desired depends on how we think our users will use the conversion. In this case, it might be okay. The string in null_book probably represents a nonexistent ISBN.

Benefits:

- Prevent the use of a constructor in a context that requires an implicit conversion
- We can define a constructor which is used only with the direct form of initialization.

Drawbacks:

- Meaningful only on constructors that can be called with a single argument

## 7.48

> Assuming the Sales_data constructors are not explicit, what op- erations happen during the following definitions
>
> ```c++
> string null_isbn("9-999-99999-9");
> Sales_data item1(null_isbn);
> Sales_data item2("9-999-99999-9")
> ```
>
> What happens if the Sales_data constructors are explicit?

Nothing happens.

## 7.49

> For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:
>
> ```c++
> // a
> Sales_data& combine(Sales_data);
> // b
> Sales_data& combine(Sales_data&); // error: the parameter is a non-const reference, we can't pass a tempory to that parameter.
> // c
> Sales_data& combine(const Sales_data&) const; // the trailing const is not wright here, putting here incidate that can not change member of Sales_data
> ```
>
> 

## 7.50

> Determine whether any of your Person class constructors should be explicit.

```c++
#include <iostream>
class Person {
  friend std::istream& read(std::istream& input, Person& p);
  friend std::ostream& write(std::ostream& output, Person& p);

 private:
  std::string name, address;

 public:
  const std::string& get_name() const { return name; }
  const std::string& get_address() const { return address; }

  Person() = default;
  Person(const std::string& name, const std::string& address)
      : name(name), address(address) {}
  explicit Person(const std::string& name) : name(name) {}
  explicit Person(std::istream& is);
};
std::istream& read(std::istream& input, Person& p);
std::ostream& write(std::ostream& output, Person& p);
```

## 7.51

> Why do you think vector defines its single-argument constructor as explicit, but string does not?

Because string can use both the copy form of initialization and diect initialization.

```c++
int getSize(const vector<int>&);
```

If vector has not defined its single-argument constructor as explicitl. We can use this function like this:

```c++
getSize(20);
```

what's that mean ? it's so weird;

## 7.52

> Using our first version of Sales_data from § 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.

In my opinion, the main problems is the aims of **Aggregate Classes**. A aggregate class should not have in-class initializers.

So:

```c++
struct Sales_data {
  std::string bookNo;
  unsigned units_sold;
  double revenue;
}
```

## 7.53

> Define your own version of Debug.

[code7.53](./exercise7_53.cpp)

## 7.54

> Should the members of Debug that begin with set_ be declared as constexpr? If not, why not?

No; the member function marked as `constexpr` is implicitly `const`,  so the `set_`  `constexpr` member function can't change the data members of const Debug object.

> The fact that this is a pointer to const means that const member functions cannot change the object on which they are called.

## 7.55

> Is the Data class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.

no;

> An aggregate class (§ 7.5.5, p. 298) whose data members are all of literal type is a literal class.

The class string is not a literal class

## 7.56

> What is a static class member? What are the advantages of static members? How do they differ from ordinary members?

static class member: a member that is associated with the class, rather than with individual objects of the class type.

Each object can no need to store a common data. and if the data is changed, each object can use the new value.

- a static data can have the same type as the class type of which it's a member. a nonstatic data member is restricted to being declared as a pointer or reference to an object of its class.
- We can use a static member as a default argument.

## 7.57

> Write your own version of the Account class.

[code7.57](./exercise7_57.h)

## 7.58

> Which, if any, of the following static data member declarations and definitions are errors? Explain why.

Fixed:

```c++
// example.h
class Example {
  public:
  	static constexpr double rate = 6.5;
  	static const int vecSize = 20;
  	static vector<double> vec;
};
// example.cpp
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```

