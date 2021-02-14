# Strings, Vectors, and Arrays

## Namespace using Declarations

Up to now, our programs have explicitly indicated that each library name we use is in the std namespace. For example, to read from the standard input, we write std::cin. These names use the **scope operator (::)** (§ 1.2, p. 8), **which says that the compiler should look in the scope of the left-hand operand for the name of the right-hand operand.** Thus, std::cin says that we want to use the name cin from the namespace std.

A using declaration lets us use a name from a namespace without qualifying the name with a` namespace_name::` prefix. A using declaration has the form:

```c++
using namepsace::name;
```

Once the using declaration has been made, we can access name directly:

```c++
#include <iostream>
using std::cin;
// using declaration; when we use the name cin, we can assess name directly
int main() {
  int i;
  cin >> i; //  ok: cin is asynonym for std::cin
  cout << i; // error: no using declaration; we must use the full name
  std::cout << i; // ok: explicitly use cout from namespace std
}
```

## Headers Should Not Include using Declarations

Code inside headers (§ 2.6.3, p. 76) ordinarily should not use using declarations. **The reason is that the contents of a header are copied into the including program’s text.** If a header has a using declaration, then every program that includes that header gets that same using declaration. As a result, a program that didn’t intend to use the specified library name might encounter unexpected name conflicts.

## Defining and Initializing strings

Each class defines how objects of its type can be initialized. A class may define many different ways to initialize objects of its type.

### Direct and Copy Forms of Initialization

When we initialize a variable using =, we are asking the compiler to **copy initialize** the object by copying the initializer on the right-hand side into the object being created. Otherwise, when we omit the =, we use **direct initialization**.

Ways to initialize a **string**

- `string s1`  Default initialization; s1 is the empty string.
- `string s2(s1)`  s2 is a copy of s1
- `string s2 = s1`  Equivalent to `s2(s1)`, s2 is a copy of s1.
- `string s3("value")` s3 is a copy of the string literal, not including the null.
- `string s3 = "value"` Equivalent to `s3("value")`, s3 is a copy of the string literal.
- `string s4(n, 'c')` Initialize s4 with n copies of the character 'c'.

## Operations on strings

String Operations:

| `os << s`        | Writes s onto output stream os. Returns os.                  |
| ---------------- | ------------------------------------------------------------ |
| `is >> s`        | Reads whitespace-separated string from is into s. Returns is. |
| `getline(is, s)` | Reads a line of input from is into s. Returns is.            |
| `s.empty()`      | Returns true if s is empty; otherwise returns false.         |
| `s.size()`       | Returns the number of characters in s.                       |
| `s[n]`           | Returns a reference to the char at position n in s; positions start at 0. |
| `s1 + s2`        | Returns a string that is the concatenation of s1 and s2.     |
| `s1 = s2`        | Replaces characters in s1 with a copy of s2.                 |
| `s1 == s2`       | The strings s1 and s2 are equal if they contain the same characters. |
| `s1 != s2`       | Equality is case-sensitive.                                  |
| `<,<=,>,>=`      | Comparisons are case-sensitive and use dictionary ordering.  |

```c++
int main() {
  string s;
  cin >> s;
  cout << s << endl;
}
```

**The string input operator reads and discards any leading whitespace (e.g., spaces, newlines, tabs). It then reads characters until the next whitespace character is encountered.**

## Using getline to Read an Entire Line

Sometimes we do not want to ignore the whitespace in our input. In such cases, we can use the getline function instead of the >> operator. The getline func- tion takes an input stream and a string. This function reads the given stream up to and including the first newline and stores what it read—not including the newline—in its string argument.

Like the input operator, getline returns its istream argument. As a result, we can use getline as a condition just as we can use the input operator as a condition.

```c++
int main() {
  string line;
  // read input a line at a time until end-of-file
  while(getline(cin, line))
    cout << line << endl;
}
```

## The string::size_type Type

The string class—and most other library types—defines several companion types. **These companion types make it possible to use the library types in a machine-independent manner.**  The type **size_type** is one of these companion types.

Although we don’t know the precise type of string::size_type, we do know that it is an unsigned type (§ 2.1.1, p. 32) big enough to hold the size of any string. Any variable used to store the result from the string size operation should be of type string::size_type.

## Adding Literals and strings

```c++
string s1 = "hello", s2 = "world"; // no punctuation in s1 or s2
string s3 = s1 + ", " s2 + '\n';
```

When we mix strings and string or character literals, **at least one operand to each + operator must be of string type:**

```c++
string s4 = s1 + ", "; // ok: adding a string and a literal
string s5 = "hello" + ", "; // error: no string oerand
string s6 = s1 + ", " + "world"; // ok: each + has a string operand
string s7 = "hello" + ", " + s2; //error: can't add string literals
```

