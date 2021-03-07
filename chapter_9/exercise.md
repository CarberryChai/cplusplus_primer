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

