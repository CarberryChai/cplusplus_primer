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

 

