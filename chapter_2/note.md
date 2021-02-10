# Variables and Basic Types

**Types are fundamental to any program: They tell us what our data mean and what operations we can perform on those data.**

## Primitive Built-in Types

 Primitive types： **arithmetic types** + `void`

The arithmetic types represent characters, integers, boolean values, and floating-point numbers. 

 The void type has no associated values and can be used in only a few circumstances, most commonly as the return type for functions that do not return a value.

**arithmetic types**: (The standard guarantees minimum sizes in this table)

|    Type     |              Meaning              |     Minimum Size      |
| :---------: | :-------------------------------: | :-------------------: |
|    bool     |              boolean              |          NA           |
|    char     |             character             |         8 bit         |
|   wchar_t   |          wide character           |        16 bits        |
|  char16_t   |         Unicode character         |        16 bits        |
|  char32_t   |         Unicode character         |        32 bits        |
|    short    |           short integer           |        16 bits        |
|     int     |              integer              |        16 bits        |
|    long     |           long integer            |        32 bits        |
|  long long  |           long integer            |        64 bits        |
|    float    |  single-precision floating-point  | 6 significant digits  |
|   double    |  double-precision floating-point  | 10 significant digits |
| long double | extended-precision floating-point | 10 significant digits |

A **char** is guaranteed to be big enough to hold numeric values corresponding to the characters in the machine’s basic char- acter set. That is, a char is the same size as a single machine byte.

The wchar_t type is guaranteed to be large enough to hold any character in the machine’s largest extended character set

 The types char16_t and char32_t are intended for Unicode characters.

> Computers store data as a sequence of bits, each holding a 0 or 1, such as 00011011011100010110010000111011 ...
>
> Most computers deal with memory as chunks of bits of sizes that are powers of 2. The smallest chunk of addressable memory is referred to as a “**byte**.” The basic unit of storage, usually a small number of bytes, is referred to as a “**word**.”
>
> Most computers associate a number (called an “address”) with each byte in memory.
>
> We can use an address to refer to any of several variously sized collections of bits starting at that address. **To give meaning to memory at a given address, we must know the type of the value stored there. The type determines how many bits are used and how to interpret those bits.**

## Type Conversions

The type of an object defines the data that an object might contain and what oper- ations that object can perform.

Type conversions happen automatically when we use an object of one type where an object of another type is expected.

```c++
bool b = 42; // b is true
int i = b; // i has value 1
i = 3.14; // i has value 3
double pi = i; // pi has value 3.0
unsigned char c = -1; // assuming 8-bit chars, c has value 255
signed char c2 = 256; // assuming 8-bit chars, the value of c2 is undefined
```

- If we assign an out-of-range value to an object of unsigned type, t**he result is the remainder of the value modulo the number of values the target type can hold.** For example, an 8-bit unsigned char can hold values from 0 through 255, inclusive. If we assign a value outside this range, the compiler assigns the remainder of that value modulo 256. Therefore, assigning –1 to an 8-bit unsigned char gives that object the value 255.

Regardless of whether one or both operands are unsigned, if we subtract a value from an unsigned, we must be sure that the result cannot be negative:

```c++
unsigned u1 = 42, u2 = 10;
std::cout << u1 - u2 << std::endl; // ok, result is 32
std::cout << u2 -u1 << std::endl; // ok, but the result will wrap around, 4294967264

```

Wite a loop that use the decrement operator to print the numbers from 10 down to 0.

```c++
for (int i = 10; i >= 0; --i)
  std::cout << i << std::endl;
```

if you use unsigned, the result of the loop will be wrong.

```c++
// Wrong: u can never be less than 0; the condition will always succed
for (unsigned u = 10; u >= 0; --u)
  std::cout << u << std::endl;
```

Consider what happens when u is 0. On that iteration, we’ll print 0 and then execute the expression in the for loop. That expression, --u, subtracts 1 from u. That result, -1, won’t fit in an unsigned value. As with any other out-of-range value, -1 will be transformed to an unsigned value. Assuming 32-bit ints, the result of --u, when u is 0, is 4294967295.

**不要混用**`signed`和`unsigned` types：

Expressions that mix signed and unsigned values can yield surprising results when the signed value is negative. It is essential to remember that signed values are auto- matically converted to unsigned.

## Literals

```c++
20 // 十进制
024 // 八进制
0x14 // 十六进制
```

The type of an integer literal depends on its value and notation. By default, deci- mal literals are signed whereas octal and hexadecimal literals can be either signed or unsigned types.

A decimal literal has the smallest type of int, long, or long long (i.e., the first type in this list) in which the literal’s value fits.

Octal and hex- adecimal literals have the smallest type of int, unsigned int, long, unsigned long, long long, or unsigned long long in which the literal’s value fits.

**There are no literals of type short.**

Although integer literals may be stored in signed types, **technically speaking, the value of a decimal literal is never a negative number. If we write what appears to be a negative decimal literal, for example, -42, the minus sign is not part of the literal. The minus sign is an operator that negates the value of its (literal) operand.**

By default, floating-point literals have type double. 

```c++
'a' // character literal
“hello world” // string literal
```

The type of a string literal is **array** of **constant chars**. The compiler appends a null character (’\0’) to every string literal. Thus, the actual size of a string literal is one more than its apparent size.

### Escape Sequences

Some characters, such as backspace or control characters, have no visible image. Such characters are **nonprintable**.

Other characters (single and double quotation marks, question mark, and backslash) have special meaning in the language. Our programs cannot use any of these characters directly. Instead, we use an escape se- quence to represent such characters. An escape sequence begins with a backslash. The language defines several escape sequences:

newline \n		horizontal tab \t		alert(bell) \a

vertial tab \v		backspace \b		double quote \"

backslash \\		question mask \?		single quote \'

carriage return \r		formfeed \f

We can also write a generalized escape sequence, which is \x followed by one or more hexadecimal digits or a \ followed by one, two, or three octal digits. The value represents the numerical value of the character. Some examples (assuming the Latin-1 character set):

\7	(bell)		\12	(newline)		\40	(blank)

\0	(null)		\115	('M')		\x4d	('M')

Note that if a \ is followed by more than three octal digits, only the first three are associated with the \. For example, "\1234" represents two characters: the char- acter represented by the octal value 123 and the character 4.

### Specifying the Type of a Literal

L'a'	// wide character literal, type is wchar_t

u8"hi!"	// utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)

42ULL	// unsigned integer literal, type is unsigned long long

1E-3F	// single-precision floating-point literal, type is float

3.14159L	// extended-precision floating-point literal, type is long double

### Boolean and Pointer Literals

```c++
bool test = false;
```

The word **nullptr** is a pointer literal.

## Variables

A **variable** provides us with named storage that our programs can **manipulate**. Each variable in C++ has a type. The type determines the size and layout of the variable’s memory, the range of values that can be stored within that memory, and the set of **operations** that can be applied to the variable.

### Initializers

An object that is initialized gets the specified value at the moment it is created. The values used to initialize a variable can be arbitrarily complicated expressions.

When a definition defines two or more variables, the name of each object becomes visible immediately. Thus, it is possible to initialize a variable to the value of one defined earlier in the same definition.

```c++
double price = 10.9, discount = price * 0.6; // ok: price is defined and initialized before it's used to initialize discount
double salePrice = applyDiscount(price, discout);
// ok: call applyDiscount and use the return value to initialize salePrice
```

### Default Initialization

When we define a variable without an initializer, the variable is default initialized.

What that default value is depends on the type of the variable and may also depend on where the variable is defined.

The value of an object of built-in type that is not explicitly initialized depends on where it is defined. Variables defined outside any function body are initialized to zero.variables of built-in type defined inside a function are **uninitialized**.

```c++
#include <iostream>
int a;
int main() {
  int b;
  std::cout << a << std::endl; // 0
  std::cout << b << std::endl; //variable 'b' is uninitialized when used here [-Werror,-Wuninitialized]
}
```

**Each class controls how we initialize objects of that class type. In particular, it is up to the class whether we can define objects of that type without an initializer. If we can, the class determines what value the resulting object will have.**

### Variable Declarations and Definitions

To allow programs to be written in logical parts, C++ supports what is commonly known as separate compilation. Separate compilation lets us split our programs into several files, each of which can be compiled independently.

To support separate compilation, C++ distinguishes between declarations and definitions.

**A declaration makes a name known to the program. A file that wants to use a name defined elsewhere includes a declaration for that name. A definition creates the associated entity.**

A variable declaration specifies the type and name of a variable. A variable definition is a declaration. In addition to specifying the name and type, a definition also allocates storage and may provide the variable with an initial value.

**Variables must be defined exactly once but can be declared many times.**

To use the same variable in multiple files, we must define that variable in one—and only one—file. Other files that use that variable must declare—but not define—that variable.

### Scope of a Name

A scope is a part of the program in which a name has a particular meaning. Most scopes in C++ are delimited by curly braces.

The same name can refer to different entities in different scopes.

```c++
#include <iostream>

int main() { // main has global scope
  int sum = 0; // main function scope
  for (int val = 1; val <= 10; ++val) // val has block scope
    sum += val;
  std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
}
```

**It is usually a good idea to define an object near the point at which the object is first used.**

## Compound Types

### References

A reference defines an alternative name for an object. A reference type "refers to" another type.

We define a reference type by writing a **declarator** of the form **&d**, where d is the name being declared:

```c++
int ival = 1024;
int &refVal = ival; // refVal refers to (is a another name for) ival
int &refVal2; // error: a reference must be initialized
```

**Ordinarily, when we initialize a variable, the value of the iniializer is copied into the object we are creating. When we define a reference, instead of copying the initializer's value, we bind the reference to its initializer;**

**Once initialized, a reference remains bound to ints initial object. The is no way to rebind a reference to refer to a different object.**

**A reference is not an object. Instead, a reference is just another name for an already existing object.**

### Reference Definitions

```c++
int i = 1024, i2 = 2048; // i and i2 are both ints
int &r = i, r2 = i2; // r is a reference bound to i; r2 is an int
int i3 = 1024, &ri = i3; // i3 is an int; ri is a reference bound to i3
int &r3 = i3, &r4 = i2; // both r3 and r4 are references
```

the type of a reference and the object to which the reference refers must match exactly. **a reference may be bound only to an object, not to a literal or to the result of a more general expression:**

```c++
int &refVal4 = 10; // error: initializer must be an object
double dval = 3.14;
int &refVal5 = dval; // error: initializer must be an int object
```

### Pointers

A pointer is a compound type that “points to” another type. Like references, point- ers are used for indirect access to other objects. Unlike a reference, a pointer is an object in its own right. Pointers can be assigned and copied;

We define a pointer type by writing a **declarator** of the form ***d,** where d is the name being defined.

```c++
int *ip1, *ip2; // both ip1 and ip2 are pointers to int
double dp, *dp2; // dp2 is a pointer to double; dp is a double
```

**A pointer holds the address of another object. We get the address of an object by usin the address-of operator (the & operator):**

```c++
int ival = 42;
int *p = &ival; // p holds the address of ival; p is a pointer to ival
```

### Null Pointers

A null pointer does not point to any object.

There are several ways to obtain a null pointer:

```c++
int *p1 = nullptr; // equivalent to int *p1 = 0;
int *p2 = 0; // directly initializes p2 from the literal constant 0
```

Given two valid pointers of the same type, we can compare them using the
equality (==) or inequality (!=) operators. The result of these operators has type bool. **Two pointers are equal if they hold the same address and unequal otherwise**

### void* Pointers

The type void* is a special pointer type that can hold the address of any object. Like any other pointer, a void* pointer holds an address, but the type of the object at that address is unknown:

```c++
double pi = 3.14, *pd = &pi;
void *pv = &pi; // ok: void* can hold the address value of any data pointer type
pv = pd;
```

## const Qualifier

