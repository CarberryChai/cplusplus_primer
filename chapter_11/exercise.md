# Exercise Chapter 11

## 11.1

> Describe the differences between a map and a vector.

`map` is a associative whereas `vector` is sequential container.

`vector` 's subscript is integer whereas is not.

## 11.2

> Give an example of when each of list, vector, deque, map, and set might be most useful.

- list : anytime when a doubly-linked list is required.
- vector : anytime when a dynamic array is required.
- deque : [An answer from SO](http://stackoverflow.com/questions/3880254/why-do-we-need-deque-data-structures-in-the-real-world).
- map : dictionary.
- set : when to keep elements sorted and unique.

## 11.3 and 11.4

> - Write your own version of the word-counting program.
> - Extend your program to ignore case and punctuation. For example, “example.” “example,” and “Example” should all increment the same counter.

[code](./exercise11_3.cpp)

## 11.5

> Explain the difference between a map and a set. When might you use one or the other?

Both `std::set` and `std::map` are associative containers. The difference is that `std::set`s contain only the key, while in `std::map` there is an associated value.

## 11.6

> Explain the difference between a set and a list. When might you use one or the other?

`set` is a associative container , while `list` is a sequential container

elements in set are unquie, while in `list` may be duplicate.

## 11.7

> Define a map for which the key is the family’s last name and the value is a vector of the children’s names. Write code to add new families and to add new children to an existing family.

[11.7code](./exercise11_7.cpp)

## 11.8

> Write a program that stores the excluded words in a vector instead of in a set. What are the advantages to using a set?

[ http://stackoverflow.com/questions/8686725/what-is-the-difference-between-stdset-and-stdvector]( http://stackoverflow.com/questions/8686725/what-is-the-difference-between-stdset-and-stdvector)

