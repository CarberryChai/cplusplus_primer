# Chapter Five Exercise

## 5.1

> What is a null statement? When might you use a null statement?

A null statement is the empty statement. A null statement is useful where the language requires a statement but the pro- gram’s logic does not. 

## 5.2

> What is a block? When might you might use a block?

A compound statement, usually referred to as a block, is a (possibly empty) se- quence of statements and declarations surrounded by a pair of curly braces. Compound statements are used when the language requires a single statement but the logic of our program needs more than one.

## 5.3

> Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite im- proves or diminishes the readability of this code.

```c++
#include <iostream>

int main() {
  int sum = 0, val = 1;
  while (val <= 10) sum += val, ++val;

  std::cout << sum << std::endl;
}
```

## 5.4

> Explain each of the following examples, and correct any problems you detect.

```c++
while (string::iterator iter != s.end()) { /* . . . */ }
```

The iterator iter must be initialized

Correct:

```c++
string::iterator iter = s.begin();
while(iter != s.end()) {/* .... */}
```

------

```c++
while(bool status = find(word)) {/* .... */}
if (!status) {/* .... */}
```

 status is not accessible outside the loop.

Correct:

```c++
bool status;
while(status = find(word)) {/* .... */}
while(bool status = find(word)) {/* .... */}
```

