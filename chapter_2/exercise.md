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

## 2.18

> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

```c++
int main() {
  int i = 42, a = 30, *p = &i;
  p = &a;
  *p = 12;
  std::<< a << std::endl; // 12
}
```

## 2.19

> Explain the key differences between pointers and references.

Definition:

A pointer is a compound type that “points to” another type.

A reference defines an alternative name for an object.

Key difference:

- a reference is just another name for an already exiting object; a pointer is an object in its own right.
- Once initialized, a reference remains bound to its initial object. The is no way to rebind a reference to refer to a different object. Because there is no way to rebind a reference, references must be initialized; Pointers can be assigned and copied, a single pointer can point to several different objects over its lifetime. a point need not be initialized at the time it is defined.

## 2.20

> What does the following program do?

```c++
int i = 42; // i is an int
int *p1 = &i; // p1 is a pointer that point to i
*p1 = *p1 * *p1; // asigning the underlying value i to 42 * 42
```

## 2.21

> Explain each of the following definitions. Indicate whether any are il- legal and, if so, why.

```c++
int i = 0;
// (a)
double *dp = &i; // 非法，dp指针所指向的对象的类型与i不同
// (b)
int *ip = i; 
// 不合法，It is illegal to assign an int variable to a pointer, even if the variable’s value happens to be 0.
// (c)
int *p = &i; // 合法
```

## 2.22

> Assuming p is a pointer to int, explain the following code:

```c++
if (p) // 判断p是否是一个nullptr
if (*p) // 判断指针p所指向的对象是否为0
```

## 2.23

> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

No; Because more information needed to determine whether the pointer is valid or not;

## 2.24

> Why is the initialization of p legal but that of lp illegal?

```c++
int i = 42;
void *p = &i;
long *lp = &i;
```

p is a `void*` pointer which can point to any type.

for lp pointer: error: cannot initialize a variable of type 'long *' with an rvalue of type 'int *'

For type safety, C++ forbids implicit conversions like `long *lp = &i;`, thus such code is illegal.

## 2.25

> Determine the types and values of each of the following variables.

```c++
// (a)
int* ip, i, &r = i;
// ip is a pointer to int; i is an int; r is a reference to i
// (b)
int i, *ip = 0;
// i is an int; ip is a pointer to nullptr
// (c)
int* ip, ip2;
// ip is a pointer to int; ip2 is an int
```

## 2.26

> Which of the following are legal? For those that are illegal, explain why.

(a)` const int buf;`

 (b)` int cnt = 0; `

(c)` const int sz = cnt;`

 (d)` ++cnt; ++sz;`

(a) illegal: must be initialized;

(d): illegal: Once a const variable be created, its value can't be changed. 

## 2.27

> Which of the following initializations are legal? Explain why.

(a)` int i = -1, &r = 0;`

Illegal: a reference must refer to an object, not to a literal

(b)` int *const p2 = &i2;`

legal

(c)` const int i = -1, &r = 0;`

legal

(d)` const int *const p3 = &i2;`

legal

(e)` const int *p1 = &i2;`

legal

(f) `const int &const r2; `

Illegal `A reference is not an object, so we cannot make a reference itself const.`

(g) `const int i2 = i, &r = i;`

Legal 

## 2.28

> Explain the following definitions. Identify any that are illegal.

(a)` int i, *const cp;`

Illegal; const object must be initilized

(b)` int *p1, *const p2;`

Illegal: the same error as (a)

(c) `const int ic, &r = ic;`

Illegal: ic must be initilized

(d) `const int *const p3;`

illegal

(e) `const int *p;`

legal

## 2.29

> Uing the variables in the previous exercise, which of the following as- signments are legal? Explain why.

(a) `i=ic;`

legal

(b)` p1=p3;`

Illegal: p3 is const pointer to const int

(c) `p1 = &ic;`

Illegal: ic is const int

(d)` p3 = &ic;`

Illegal: p3 is const pointer

(e) `p2=p1;`

Illegal: p2 is const pointer

(f)` ic=*p3;`

Illegal: ic is const int

## 2.30

> For each of the following declarations indicate whether the object being declared has top-level or low-level const.

```c++
const int v2 = 0; // top-level const
int v1 = v2; // top-level const in v2 is ignored
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2; 
// p2 is low-level const, p3 is both top-level and low-leve const; r2 is low-level const
```

## 2.31

> Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.

```c++
r1 = r2; // legal; top-level const in r2 is ignored
p1 = p2; // illegal; p2 has low-level const but p1 doesn't
p2 = p1; // ok; we can covert int* to const int*
p1 = p3; // illegal;
p2 = p3; // ok; both p2 and p3 have the sam low-level const qualification
```

## 2.32

> Is the following code legal or not? If not, how might you make it legal?

```c++
int null = 0, *p = null;
```

illegal; `int null = 0, *p = nullprr;`

