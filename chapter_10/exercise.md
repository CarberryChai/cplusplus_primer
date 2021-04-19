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

## 10.11

> Write a program that uses stable_sort and isShorter to sort a vector passed to your version of elimDups. Print the vector to verify that your program is correct.

[10.11code](./exercise10_11.cpp)

## 10.12

> Write a function named compareIsbn that compares the isbn() members of two Sales_data objects. Use that function to sort a vector that holds Sales_data objects.

[10.12code](./exercise10_12.cpp)

## 10.13

> The library defines an algorithm named partition that takes a pred- icate and partitions the container so that values for which the predicate is true appear in the first part and those for which the predicate is false appear in the second part. The algorithm returns an iterator just past the last element for which the predicate returned true. Write a function that takes a string and returns a bool indicating whether the string has five characters or more. Use that function to partition words. Print the elements that have five or more characters.

[10.13code](./exercise10_13.cpp)

## 10.14

> Write a lambda that takes two ints and returns their sum.

[10.14code](./exercise10_14.cpp)

## 10.15

>  Write a lambda that captures an int from its enclosing function and takes an int parameter. The lambda should return the sum of the captured int and the int parameter.

[10.15code](./exercise10_15.cpp)

## 10.16

> Write your own version of the biggies function using lambdas.

[10.16code](./exercise10_16.cpp)

## 10.17

> Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the call to sort instead of the compareIsbn function.

[10.17code](./exercise10_17.cpp)

## 10.18 、10.19

> - Rewrite biggies to use partition instead of find_if. We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).
> - Rewrite the previous exercise to use stable_partition, which like stable_sort maintains the original element order in the paritioned sequence.

[10.18code](./exercise10_18.cpp)

## 10.20

> The library defines an algorithm named count_if. Like find_if, this function takes a pair of iterators denoting an input range and a predicate that it applies to each element in the given range. count_if returns a count of how often the predicate is true. Use count_if to rewrite the portion of our program that counted how many words are greater than length 6.

[10.20code](./exercise10_20.cpp)

## 10.21

> Write a lambda that captures a local int variable and decrements that variable until it reaches 0. Once the variable is 0 additional calls should no longer decrement the variable. The lambda should return a bool that indicates whether the captured variable is 0.

[10.21code](./exercise10_20.cpp)

## 10.22

> Rewrite the program to count words of size 6 or less using functions in place of the lambdas.

[10.22code](./exercise10_22.cpp)

## 10.23

> How many arguments does bind take?

Assuming the function to be bound has `n` parameters, bind will take `n + 1` parameters .

## 10.24

> Use bind and check_size to find the first element in a vector of ints that has a value greater than the length of a specified string value.

[10.24code](./exercise10_24.cpp)

## 10.25

> In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies that uses partition. Rewrite that function to use check_size and bind.

[10.25code](./exercise10_25.cpp)

## 10.26

> Explain the differences among the three kinds of insert iterators.

- `back_inserter` creates an iterator that use `push_back`
- `front_inserter` creates an iterator that uses `push_front`
- This function takes a second argument, which must be an iterator into the given container. Elements are inserted ahead of the element denoted by the given iterator.

## 10.27

> In addition to unique (§ 10.2.3, p. 384), the library defines function named unique_copy that takes a third iterator denoting a destination into which to copy the unique elements. Write a program that uses unique_copy to copy the unique elements from a vector into an initially empty list.

[10.27code](./exercise10_27.cpp)

真坑，必须是连续重复的才能去重！！

`std::unique_copy`:

Copies the elements from the range `[first, last)`, to another range beginning at `d_first` in such a way that **there are no consecutive equal elements.** Only the first element of each group of equal elements is copied.

## 10.28

> Copy a vector that holds the values from 1 to 9 inclusive, into three other containers. Use an inserter, a back_inserter, and a front_inserter, respectivly to add elements to these containers. Predict how the output sequence varies by the kind of inserter and verify your predictions by running your programs.

[10.28code](./exercise10_28.cpp)

## 10.29

> Write a program using stream iterators to read a text file into a vector of strings.

[10.29code](./exercise10_29.cpp)

## 10.30 and 10.31

> - Use stream iterators, sort, and copy to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.
> - Update the program from the previous exercise so that it prints only the unique elements. Your program should use unqiue_copy (§ 10.4.1, p. 403).

[10.30code](./exercise10_30.cpp)

## 10.32

> Rewrite the bookstore problem from § 1.6 (p. 24) using a vector to hold the transactions and various algorithms to do the processing. Use sort with your compareIsbn function from § 10.3.1 (p. 387) to arrange the transactions in order, and then use find and accumulate to do the sum.

[10.32code](./exercise10_32.cpp)

## 10.33

> Write a program that takes the names of an input file and two output files. The input file should hold integers. Using an istream_iterator read the input file. Using ostream_iterators, write the odd numbers into the first output file. Each value should be followed by a space. Write the even numbers into the second file. Each of these values should be placed on a separate line.

[10.33code](./exercise10_33.cpp)

