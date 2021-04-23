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

## 11.9 and 11.10

> - Define a map that associates words with a list of line numbers on which the word might occur.
> - Could we define a map from vector<int>::iterator to int? What about from list<int>::iterator to int? In each case, if not, why not?

> For the ordered containers—map, multimap, set, and multiset—the key type must define a way to compare the elements. By default, the library uses the < operator for the key type to compare the keys.

[11.9code](./exercise11_9.cpp)

## 11.11

> Redefine bookstore without using decltype.

```c++
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
  return lhs.isbn() < rhs.isbn();
}
multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
```

## 11.12 and 11.13

> - Write a program to read a sequence of strings and ints, storing each into a pair. Store the pairs in a vector.
> - There are at least three ways to create the pairs in the program for the previous exercise. Write three versions of that program, creating the pairs in each way. Explain which form you think is easiest to write and understand, and why.

[11.12code](./exercise11_12.cpp)

## 11.14

> Extend the map of children to their family name that you wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a pair that holds a child’s name and birthday.

[11.14code](./exercise11_14.cpp)

## 11.15

> What are the mapped_type, key_type, and value_type of a map from int to vector<int>?

```c++
map<int, vector<int>> m;
map<int, vector<int>>::mapped_type v; // vector<int>
map<int, vector<int>>::key_type x; // int
map<int, vector<int>>::value_type mp; // pair<const int, vector<int>>
```

## 11.16

> Using a map iterator write an expression that assigns a value to an element.

```c++
map<int, string> m;
auto it = m.begin();
it->second = "hello";
```

## 11.17

> Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal:

```c++
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`.
copy(c.begin(), c.end(), inserter(v, v.end())); // legal.
copy(c.begin(), c.end(), back_inserter(v)); // legal.
```

## 11.18

> Write the type of map_it from the loop on page 430 without using auto or decltype.

```c++
map<string, size_t>::const_iterator map_it = word_count.cbegin();
while(map_it != word_count.cend()) {
  cout << map_it->first << " occurs " << map_it->second << " times" << endl;
  ++map_it;
}
```

## 11.19

> Define a variable that you initialize by calling begin() on the multiset named bookstore from § 11.2.2 (p. 425). Write the variable’s type without using auto or decltype.

```c++
multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)>::iterator it = bookstore.begin();
```

## 11.20

> Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read? Explain your reasoning.

[11.20code](./exercise11_20.cpp)

## 11.21

> Assuming word_count is a map from string to size_t and word is a string, explain the following loop:

```c++
while (cin >> word)
  ++word_count.insert({word, 0}).first->second;
```

```c++
while (cin >> word) {
  auto result = word_count.insert({word, 0});
  auto item = result.first;
  ++item->second;
}
```

## 11.22

> Given a map<string, vector<int>>, write the types used as an argument and as the return value for the version of insert that inserts one element.

argument: `pair<string, vector<int>>`

Return type: `pair<map<string, vector<int>>::iterator, bool>`

## 11.23

> Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap.

[11.23code](./exercise11_23.cpp)