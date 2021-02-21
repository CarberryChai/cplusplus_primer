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
if (!status) {/* .... */}
```

## 5.5

> Using an if–else statement, write your own version of the program to generate the letter grade from a numeric grade.

[code](./exercise5_5.cpp)

## 5.6

> Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.

[code](./exercise5_6.cpp)

## 5.7

> Correct the errors in each of the following code fragments:

- ```c++
  if (ival1 != ival2) ival1 = ival2;
  else ival1 = ival2 = 0;
  ```

- ```c++
  if (ival < minval) {
    minval = ival;
    occurs = 1;
  }
  ```

- ```c++
  if (int ival = get_value()) {
    cout << "ival = " << ival << endl;
    if(!ival) cout << "ival = 0\n";
  }
  ```

- ```c++
  if (ival == 0) ival = get_value();
  ```

## 5.8

> What is a “dangling else”? How are else clauses resolved in C++?

“dangling else” is the problem how we know to which if a given else belongs.

In C++ the ambiguity is resolved by specifying that each else is matched with the closest preceding unmatched if.

## 5.9

> Write a program using a series of if statements to count the number of vowels in text read from cin.

[code](./exercise5_9.cpp)

## 5.10

> There is one problem with our vowel-counting program as we’ve im- plemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both ’a’ and ’A’ as part of aCnt, and so forth.

[code](./exercise5_10.cpp)

## 5.11

> Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.

[code](./exercise5_11.cpp)

## 5.12

> Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: ff, fl, and fi.

## 5.13

> Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.

```c++
// (a)
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
  case 'a': aCnt++; break;
  case 'e': eCnt++; break;
  default: iouCnt++;
} // 缺少break语句
```

------

```c++
// (b)
unsigned index = some_value();
int ix;
switch (index) {
  case 1:
    ix = get_value();
    ivec[ix] = index;
    break;
  default:
    ix = ivec.size() -1;
    ivec[ix] = index;
} // error: control bypasses an explicitly initialized variable
```

------

```c++
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
  case 1: case 3: case 5: case 7: case 9:
    oddCnt++;
    break;
  case 2: case 4: case 6: case 8: case 10:
    eventCnt++;
    break;
}
```

------

```c++
const unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
  case ival:
    bufsize = ival * sizeof(int);
    break;
  case jval:
    bufsize = jval * sizeof(int);
    break;
  case kval:
    bufsize = kval * sizeof(int);
    break;
} // nonconstant as case label
```

## 5.14

> Write a program to read strings from standard input looking for du- plicated words. The program should find places in the input where one word is fol- lowed immediately by itself. Keep track of the largest number of times a single repeti- tion occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is
>
> > how now now now brown cow cow
>
> the output should indicate that the word now occurred three times.

[code](./exercise5_14.cpp)

## 5.15

> Explain each of the following loops. Correct any problems you detect.

```c++
for (int x = 0; ix != sz; ++ix) { 
	if(ix != sz)
    // ...
}
// can't access ix outside for loop
```

------

```c++
int ix;
for (; ix != sz; ++ix) { /* ... */ }
// 初始化语句不能省略，可以为空
```

------

```c++
for (int ix = 0; ix != sz; ++ix) {}
```

## 5.16

> The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The for loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

```c++
// while idiomatic
int ix = 0;
while (ix != sz) {
  ++ix;
}
// the same as
for( int ix = 0; ix != sz; ++ix) {
  // ...
}
// for idiomatic
for(auto it = vec.begin(); it != vec.end(); ++it){
  // ...
}
// the same as
auto it = vec.begin();
while(it != vec.end()){
  ++it;
  // ... 
}
```

I have no prefer.

## 5.17

> Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the num- ber of elements of the smaller vector. For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.

[code](./exercise5_17.cpp)

## 5.18

> Explain each of the following loops. Correct any problems you detect.

```c++
do {
  int v1, v2;
  cout << "Please enter two numbers to sum: ";
  if(cin >> v1 >> v2) cout<< "Sum is: " << v1 + v2 << endl;
} while(cin);
```

------

```c++
int ival;
do {
  // ....
} while(ival = get_response())
```

------

```c++
int ival;
do {
  ival = get_response();
} while (ival);
```

## 5.19

> Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.

[code](./exercise5_19.cpp)