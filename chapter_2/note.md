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

