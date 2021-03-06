# Exercise Chapter Eight

## 8.1 and 8.2

> Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

------

> Test your function by calling it, passing cin as an argument.

[code8.1](./exercise8_1.cpp)

## 8.3

> What causes the following while to terminate?

```c++
while (cin >> i) {
  // ...
}
```

the `istream` cin reach the end-of-file or occur an error, both set `eofbit` , `failbit`, respectively.

## 8.4

> Write a function to open a file for input and read its contents into a vector of strings, storing each line as a separate element in the vector.

[code8.4](./exercise8_4.cpp)

## 8.5

> Rewrite the previous program to store each word in a separate element.

[code8.5](./exercise8_5.cpp)

## 8.6

> Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transac- tions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).

[code8.6](./exercise8_6.cpp)

## 8.7

> Revise the bookstore program from the previous section to write its out- put to a file. Pass the name of that file as a second argument to main.

[code8.7](./exercise8_7.cpp)

## 8.8

> Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure that the data are preserved.

[code8.8](./exercise8_8.cpp)

## 8.9

> Use the function you wrote for the first exercise in § 8.1.2 (p. 314) to print the contents of an istringstream object.

[code8.9](./exercise8_9.cpp)

## 8.10

> Write a program to store each line from a file in a vector<string>. Now use an istringstream to read each element from the vector a word at a time.

[code8.10](./exercise8_10.cpp)

## 8.11

> The program in this section defined its istringstream object inside the outer while loop. What changes would you need to make if record were defined outside that loop? Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.

[code8.11](exercise8_13.cpp)

## 8.12

> Why didn’t we use in-class initializers in PersonInfo?

Because we need an aggregate class, so there is no need in-class initializers.

## 8.13

> Rewrite the phone number program from this section to read from a named file rather than from cin.

[code8.13](exercise8_11.cpp)

## 8.14

> Why did we declare entry and nums as const auto &?

- They are all class type, not the built-int type, so **reference** is more effective.
- We don't want to change their values, so we added the `const`.