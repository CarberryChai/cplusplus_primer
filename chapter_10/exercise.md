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

