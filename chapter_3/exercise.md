# Chapter Three Exercise

## 3.1

> Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.

[code-part-a](./exercise3_1a.cpp)

[code-part-b](./exercise3_1b.cpp)

## 3.2

> Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

[code-part-a](./exercise3_2a.cpp)

[code-part-b](./exercise3_2b.cpp)

## 3.3

> Explain how whitespace characters are handled in the string input op- erator and in the getline function.

- The string input operator reads and discards any leading whitespace (e.g., spaces, newlines, tabs). It then reads characters until the next whitespace character is encountered.
- This function reads the given stream up to and including the first newline and stores what it read—not including the newline—in its string argument.

## 3.4

> Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.

[code-part-a](./exercise3_4a.cpp)

[code-part-b](./exercise3_4b.cpp)

## 3.5

> Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.

[code-part-a](./exercise3_5a.cpp)

[code-part-b](./exercise3_5b.cpp)

## 3.6

> Use a range for to change all the characters in a string to X.

[code](exercise3_6.cpp)

## 3.7

> What would happen if you define the loop control variable in the previ- ous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

```c++
 std::string str;
  while (std::cin >> str) {
    for (char &c : str) c = 'X';
    std::cout << str << std::endl;
  }
```

Change the for loop control variable `char&` to `char`, then the `char` is a copy of each character of `str`, changing the copy can not change the original string. Its do nothing.

## 3.8

> Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?

[while](./exercise3_8a.cpp)

[traditional for](./exercise3_8b.cpp)

I prefer range for and traditional for. No why.

## 3.9

> What does the following program do? Is it valid? If not, why not?

```c++
string s;
cout << s[0] << endl;
```

Whenever we use a subscript, we should think about how we know that it is in range.

 The program is to print the first character of string s.  Since `s` is empty, such operation is invalid, a.k.a. **undefined behavior**.

## 3.10

> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

[code](exercise3_10.cpp)

## 3.11

> Is the following range for legal? If so, what is the type of c?

```c++
const string s = "Keep out!";
for (auto &c :s) {// ....}
```

Yes, legal, the type of c is `const char&`

 ## 3.12

> Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.

```c++
vector<vector<int>> ivec; // legal; define a vector whose elements are vector
vector<string> svec = ivec; // error: vector<vector<int>> can't assign to type of vector<string>
vector<string> svec(10, "null"); // legal; svec has ten elements with value "null"
```

## 3.13

> How many elements are there in each of the following vectors? What are the values of the elements?

```c++
vector<int> v1; // zero
vector<int> v2(10) // v2 has ten elements with value 0
vector<int> v3(10, 42); // v3 has ten elements with value 42
vector<int> v4{10}; // v4 has one element with 10
vector<int> v5{10, 42}; // v5 has two elements with value 10 and 42
vector<string> v6{10}; // v6  has ten elements with value ""
vector<string> v7{10, "hi"}; // v7 has ten elements with value "hi"
```

## 3.14

> Write a program to read a sequence of ints from cin and store those values in a vector.

[code](./exercise3_14.cpp)

## 3.15

> Repeat the previous program but read strings this time.

[code](./exercise3_15.cpp)

## 3.16

> Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.

[code](./exercise3_16.cpp)

## 3.17

> Read a sequence of words from cin and store the values a vector. Af- ter you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.

[code](./exercise3_17.cpp)

## 3.18

> Is the following program legal? If not, how might you fix it?
>
> ```c++
> vector<int> ivec;
> ivec[0] = 42;
> ```
>
> 

Illegal ;

Fixed:

```c++
vector<int> ivec{0};
ivec[0] = 42;
```

## 3.19

> List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

- `vector<int> ivec(10, 42)`

- `vector<int> ivec{42, 42, 42, 42, 42, 42, 42, 42, 42, 42}`

- ```c++
  vector<int> ivec(10);
  for(auto &i : ivec) i = 42;
  ```

The first is best;

## 3.20

> Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

[sum of each pair](./exercise3_20a.cpp)

[sum of the first and the last](./exercise3_20b.cpp)

## 3.21

> Redo the first exercise from § 3.3.3 (p. 105) using iterators.

[code](./exercise3_21.cpp)

## 3.22

> Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.

[code](./exercise3_22.cpp)

## 3.23

> Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.

[code](./exercise3_23.cpp)

## 3.24

> Redo the last exercise from § 3.3.3 (p. 105) using iterators.

[sum of each pair](./exercise3_24a.cpp)

[sum of the first and the last](./exercise3_24b.cpp)

## 3.25

> Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.

[code](./exercise3_25.cpp)

## 3.26

> In the binary search program on page 112, why did we write mid = beg +(end-beg)/2;instead ofmid=(beg+end)/2;?

There's no operator `+` for adding two iterators.

## 3.27

> Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.

```c++
unsigned buf_size = 1024;
int ia[buf_size]; // illegal; buf_size is not an constexpr
int ia[4*7 - 14]; //legal; 
int ia[txt_size()]; // illegal; the return type of txt_size function is not constexpr
char str[11] = "fundamental"; // illegal; no space for null
```

## 3.28

>  What are the values in the following arrays?

```c++
string sa[10]; // sa is array of ten string type with value ""
int ia[10]; // ia is array of ten ints with value 0
int main() {
  string sa2[10]; // sa2 is array of ten string type with value ""
  int ia[10]; // ia is array of ten ints with undefine value
}
```

## 3.29

> List some of the drawbacks of using an array instead of a vector.

- Fixed size at compile time
- No Api for array type

## 3.30

> Identify the indexing errors in the following code:

```c++
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
  		ia[ix] = ix;
```

across the  array boundary; when ix is 10, it's trying dereference an element out of range;

## 3.31

> Write a program to define an array of ten ints. Give each element the same value as its position in the array.

[code](./exercise3_31.cpp)

## 3.32

> Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.

[code-part-a](./exercise3_32a.cpp)

[code-part-b](./exercise3_32b.cpp)

## 3.33

>  What would happen if we did not initialize the scores array in the program on page 116?

If so, values of array are undefined, we would get unexpected result when increment the undefined value.

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/3wrhPB-ARR1Ss.png" style="zoom:50%;" />

## 3.34

> Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?

No , it's legal

## 3.35

> Using pointers, write a program to set the elements in an array to zero.

[code](./exercise3_35.cpp)

## 3.36

> Write a program to compare two arrays for equality. Write a similar program to compare two vectors.]

[code](./exercise3_36.cpp)

## 3.37

> What does the following program do?

```c++
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca; // now cp points to the first element in array ca
while(*cp) {
  cout << *cp << endl; // print the character in ca
  ++cp; // move cp to next element
}
// because ca has no null character (’\0’), the while loop won't be terminated as expected
```

## 3.38

> In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

------

Answer:

> Pointer addition is forbidden in C++, you can only subtract two pointers.
>
> The reason for this is that subtracting two pointers gives a logically explainable result - the offset in memory between two pointers. Similarly, you can subtract or add an integral number to/from a pointer, which means "move the pointer up or down". Adding a pointer to a pointer is something which is hard to explain. What would the resulting pointner represent?
>
> If by any chance you explicitly need a pointer to a place in memory whose address is the sum of some other two addresses, you can cast the two pointers to `int`, add `int`s, and cast back to a pointer. Remember though, that this solution needs huge care about the pointer arithmetic and is something you really should never do.

[for detail](https://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)

## 3.39

> Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.

[code](./exercise3_39.cpp)

## 3.40

> Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.

[code](./exercise3_40.cpp)

## 3.41

> Write a program to initialize a vector from an array of ints.

[code](./exercise3_41.cpp)

## 3.42

> Write a program to copy a vector of ints into an array of ints.

[code](./exercise3_42.cpp)

## 3.43、3.44、3.45

> Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.

[code](./exercise3_43_44_45.cpp)