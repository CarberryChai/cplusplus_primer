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