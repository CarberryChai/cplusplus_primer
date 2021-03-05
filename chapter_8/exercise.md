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