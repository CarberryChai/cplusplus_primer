# Exercise Chapter 9

## 9.1

> Which is the most appropriate—a vector, a deque, or a list—for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.

(a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.

`list` 

> If the program needs to insert or delete elements in the middle of the container, use a list or forward_list.

(b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.

`deque`

> If the program needs to insert or delete elements at the front and the back, but not in the middle, use a deque.

(c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

`vector`

## 9.2

> Define a list that holds elements that are deques that hold ints.

```c++
list<deque<int>> l;
```

## 9.3

> What are the constraints on the iterators that form iterator ranges?

- The iterators `begin` and `end` must refer to the same container.
- The iterator `end` may be equal to `begin` but must not refer to an element before the one denoted by `begin`.

## 9.4

> Write a function that takes a pair of iterators to a vector<int> and an int value. Look for that value in the range and return a bool indicating whether it was found.

[code9.4](./exercise9_4.cpp)

## 9.5

> Rewrite the previous program to return an iterator to the requested ele- ment. Note that the program must handle the case where the element is not found.

[code9.5](./exercise9_5.cpp)

## 9.6

> What is wrong with the following program? How might you correct it?
>
> ```c++
> list<int> lst1;
> list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
> while(iter1 < iter2) {
>   // ...
> }
> ```
>
> 

there is no `<` relational operator in `list` container.

Fixed:

```c++
while(iter1 != iter2) {
  // ...
}
```

## 9.7

> What type should be used as the index into a vector of ints?

```c++
vector<int>::size_type idx = 0;
```

## 9.8

> What type should be used to read elements in a list of strings? To write them?

```c++
list<string>::const_reference v;
list<string>::reference;
```

## 9.9

> What is the difference between the begin and cbegin functions?

When we call begin function, the yielded iterator type depends on the container type. We get a const version of the iterators only when call the begin on a const object, otherwise we get a plain iterator.

The cbegin function let us get a `const_iterator` regardless of the type of the container.

## 9.10

> What are the types of the following four objects?

```c++
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(); // vector<int>::interator
auto it2 = b2.begin(); // vector<int>::const_iterator
auto it3 = v1.cbegin(); // vector<int>::const_iterator
auto it4 = v2.cbegin(); // vector<int>::const_iterator
```

## 9.11

> Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

[code9.11](./exercise9_11.cpp)

## 9.12

> Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

-  When we initialize a container as a copy of another container, the container type and element type of both containers must be identical.

- When we pass iterators, there is no requirement that the con- tainer types be identical. Moreover, the element types in the new and original containers can differ as long as it is possible to convert (§ 4.11, p. 159) the elements we’re copying to the element type of the container we are initializing:

  ```c++
  vector<const int*> articles = {"a", "an", "the"};
  forward_list<string> words(articles.begin(), articles.end());
  ```

## 9.13

>  How would you initialize a vector<double> from a list<int>? From a vector<int>? Write code to check your answers.

[code9.13](./exercise9_13.cpp)

## 9.14

> Write a program to assign the elements from a list of` char*` pointers to C-style character strings to a vector of strings.

[code9.14](./exercise9_14.cpp)

## 9.15 and 9.16

> Write a program to determine whether two `vector<int>`s are equal.
>
> Repeat the previous program, but compare elements in a `list<int>` to a `vector<int>.`

[code9.15](./exercise9_15.cpp)

## 9.17

> Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?

```c++
if (c1 < c2)
```

- If c1 and c2 are unordered associative constainers, which don't suuport the relational operators (>, >=, <, <=), so their comparison is invalid.
- If containers of c1 and c2 support relational operators, but the element type doesn't support, we can't use the corresponding operations on containers holding that type.

## 9.18

> Write a program to read a sequence of strings from the standard input into a deque. Use iterators to write a loop to print the elements in the deque.

[code9.18](./exercise9_18.cpp)

## 9.19

> Rewrite the program from the previous exercise to use a list. List the changes you needed to make.

[code9.19](./exercise9_19.cpp)

## 9.20

> Write a program to copy elements from a list<int> into two deques. The even-valued elements should go into one deque and the odd ones into the other.

[code9.20](./exercise9_20.cpp)

## 9.21

> Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.

it's the same.

But :

>  It is legal to insert anywhere in a vector, deque, or string. However, doing so can be an expensive operation.

> Before the loop, we initialize iter to lst.begin(). The first call to insert takes the string we just read and puts it in front of the element denoted by iter. The value returned by insert is an iterator referring to this new element. We assign that iterator to iter and repeat the while, reading another word. As long as there are words to insert, each trip through the while inserts a new element ahead of iter and reassigns to iter the location of the newly inserted element. That element is the (new) first element. Thus, each iteration inserts an element ahead of the first element in the list

## 9.22

> Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?
>
> ```c++
> vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
> while (iter != mid )
>   if (*iter == some_val)
>     iv.insert(iter, 2 * some_val);
> ```

// TODO

## 9.23

> In the first program in this section on page 346, what would the values of `val`, `val2`, `val3`, and `val4` be if `c.size()` is 1?

```c++
if (!c.empty()) {
  auto val = *c.begin(), val2 = c.front();
  auto last = c.end();
  auto val3 = *(--last);
  auto val4 = c.back();
}
```

Assume that `vector<int> c{1};`

```c++
val == val2 == val3 == val4;
```

## 9.24

> Write a program that fetches the first element in a vector using at, the subscript operator, front, and begin. Test your program on an empty vector.

[code9.24](./exercise9_24.cpp)

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/EfQFx3-df1hJO.png" style="zoom:50%;" />

