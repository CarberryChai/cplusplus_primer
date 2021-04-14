# Exercise Chapter 10

## 10.1

> The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the count of how many elements have a given value.

[10.1code](./exercise10_1.cpp)

## 10.2

> Repeat the previous program, but read values into a list of strings.

[10.1code](./exercise10_1.cpp)

## 10.3

> Use accumulate to sum the elements in a vector<int>.

[10.3code](./exercise10_3.cpp)

## 10.4

> Assuming v is a` vector<double>`, what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?

It will convert all double elements in vector container to int, and will loss precision.

## 10.5

> In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?

For such case, std::equal is going to compare the address value rather than the string value. So the result is not the same as `std::string`. Try to avoid coding this way.

[see detail](https://github.com/Mooophy/Cpp-Primer/issues/227)

## 10.6

> Using fill_n, write a program to set a sequence of int values to 0.

[10.6code](./exercise10_6.cpp)

## 10.7

> Determine if there are any errors in the following programs and, if so, correct the error(s):

```c++
// a
vector<int> vec; list<int> lst; int i;
while(cin >> i)
  lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
```

>  Algorithms that write to a destination iterator assume the destination is large enough to hold the number of elements being written.

So:

```c++
copy(lst.cbegin(), lst.end(), back_inserter(vec))
```

```c++
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);
```

> reserve does not change the number of elements in the container; it affects only how much memory the vector preallocates.

> When we use an algorithm that assigns to elements, we must take care to ensure that the sequence into which the algorithm writes is at least as large as the number of elements we ask the algorithm to write. Remember, **algorithms do not perform container oper- ations, so they have no way themselves to change the size of a container.**

So:

```c++
fill_n(back_inserter(vec), 10, 0);
```

## 10.8

> We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?

Inserters like `back_inserter` is part of `<iterator>`, rather than `<algorithm>`

> An insert iterator is an iterator that adds elements to a container. Ordinarily, when we assign to a container element through an iterator, we assign to the element that iterator denotes. When we assign through an insert iterator, a new element equal to the right-hand value is added to the container.

## 10.9

> Implement your own version of elimDups. Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.

[10.9code](./exercise10_9.cpp)

## 10.10

> Why do you think the algorithms don’t change the size of containers?

Cause the library algorithms operate on **iterators**, **not containers**. Thus, an algorithm **cannot (directly)** add or remove elements.