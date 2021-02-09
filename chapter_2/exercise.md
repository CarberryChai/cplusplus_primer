# Chapter Two Exercise

## 2.1

> What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

## C++ guarantees `short` and `int` is **at least** 16 bits, `long` **at least** 32 bits, `long long` **at least** 64 bits.

The `signed` can represent positive numbers, negative numbers and zero, while `unsigned` can only represent numbers no less than zero.

The C and C++ standards do not specify the representation of float, double and long double. It is possible that all three implemented as IEEE double-precision. Nevertheless, for most architectures (gcc, MSVC; x86, x64, ARM) float is indeed a IEEE **single-precision** floating point number (binary32), and double is a IEEE **double-precision** floating point number (binary64).

Usage:

- Use `int` for integer arithmetic. `short` is usually too small and, in practice, `long` often has the same size as `int`. If your data values are larger than the minimum guaranteed size of an `int`, then use `long long`. (In a word: short < **int** < long < long long)
- Use an unsigned type when you know that the values cannot be negative. (In a word: no negative, unsigned.)
- Use double for floating-point computations; float usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible. In fact, on some machines, double-precision operations are faster than single. The precision offered by long double usually is unnecessary and often entails considerable run-time cost. (In a word: float < **double** < long double)

ref:

- [What are the criteria for choosing between `short` / `int` / `long` data types?](https://isocpp.org/wiki/faq/newbie#choosing-int-size)
- [What is the difference between float and double?](https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double)

## 2.2

> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

use `double`, or also `float`.

The rate most like that: 4.50 % per year. The principal most like that: $854.36 The payment most like that: $1, 142.36

## 2.3

>  What output will the following code produce?

```c++
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl; // 32
std::cout << u - u2 << std::endl; // 4294967264
int i = 10; i2 = 42;
std::cout << i2 - i << std::endl; // 32
std::cout << i - i2 << std::endl; // -32
std::cout << i - u << std::endl; // 0
std::cout << u - i << std::endl; // 0
```

# 2.4

> Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

[code](./exercise2_4.cpp)

## 2.5

> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

(a) ’a’,L’a’,"a",L"a"

character literal, wide character literal, string literal, string wide character literal

(b) 10,10u,10L,10uL,012,0xC

int, unsigned int, long, unsigned long, octal int, hexadecimal

(c) 3.14,3.14f,3.14L

double, float, long double

(d) 10,10u,10.,10e-2

int, unsigned int, double, double

## 2.6

> What, if any, are the differences between the following definitions:

```c++
int month = 9, day = 7; // valid, the type is int
int month = 09, day = 07; // invalid digit '9' in octal constant
```

## 2.7

> What values do these literals represent? What type does each have?

(a) "Who goes with F\145rgus?\012"

represent:  "Who goes with Fergus?(newline)"

(b) 3.14e1L

31.4 (long double)

(c) 1024f

 error: invalid digit 'f' in decimal constant

(d) 3.14L

3.14 (long double)

## 2.8

> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

[code](./exercise2_8.cpp)

