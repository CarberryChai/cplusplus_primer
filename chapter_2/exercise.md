# Chapter Two Exercise

## 2.1

> What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

**C++ guarantees `short` and `int` is at least 16 bits, `long` at least 32 bits, `long long` at least 64 bits.**

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

## 2.9

> Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.

(a) std::cin >> int input_value;

error: expected '(' for function-style cast or type construction

```c++
int input_value;
std::cin >> input_value;
```

(b) int i = { 3.14 };

 error: type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]

(c) double salary = wage = 9999.99;

error: use of undeclared identifier 'wage'

```c++
double wage;
double salary = wage = 9999.99;
```

(d) int i = 3.14;

Ok, but the value will be truncated.

## 2.10

> What are the initial values, if any, of each of the following variables?

```c++
std::string global_str; // ""
int global_int; // 0
int main() {
  int local_int; // variable 'local_int' is uninitialized when used here [-Werror,-Wuninitialized]
  std::string local_str; // ""
}
```

## 2.11

> Explain whether each of the following is a declaration or a definition:

(a) extern int ix = 1024;

definition

(b) int iy;

definition

(c) extern int iz;

declaration

## 2.12

> Which, if any, of the following names are invalid?

```c++
int double = 3.14; // invalid
int _; // valid
int catch-22; // invalid
int 1_or_2 = 1; // invalid
double Double = 3.14; // valid
```

## 2.13

> What is the value of j in the following program?

```c++
int i = 42;
int main() {
  int i = 100;
  int j = i; // 100;
}
```

## 2.14

>  Is the following program legal? If so, what values are printed?

```c++
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i)
		sum += i;
	std::cout << i << " " << sum << std::endl;
```

合法，打印：100 45

## 2.15

> Which of the following definitions, if any, are invalid? Why?

(a) int ival = 1.01;

(b) int &rval1 = 1.01;

(c) int &rval2 = ival;    

(d) int &rval3;

(b) invalid; initializer must be an object 

(d) invalid; references must be initialized.

## 2.16

> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
>
> ```c++
> int i = 0, &r1 = i; double d = 0, &r2 = d;
> ```
>
> 

(a) r2 = 3.14159;

Valid; assign 3.14159 to d;

(b) r2 = r1;

valid; assign 0 to d;

(c) i=r2; 

valid; 

(d) r1=d;

valid;

## 2.17

> What does the following code print?

```c++
int i, &ri = i;
i = 5; ri = 10;
std::cout << i < " " << ri << std::endl;
```

10 10

