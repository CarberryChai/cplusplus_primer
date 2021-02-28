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

