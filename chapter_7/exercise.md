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

