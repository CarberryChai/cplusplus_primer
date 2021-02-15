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

## Processing Every Character? Use Range-Based for

If we want to do something to every character in a string, by far the best approach is to use a statement introduced by the new standard: the **range for** statement.

**This statement iterates through the elements in a given sequence and performs some operation on each value in that sequence.** The syntactic form is

​	for (*declaration* :  *expression*)

​			*statement*

A string represents a sequence of characters, so we can use a string as the expression in a **range for**.

```c++
string str("some thing");
for (auto c : str)
  cout << c << endl;
```

As a somewhat more complicated example, we’ll use a **range for** and the ispunct function to count the number of punctuation (标点符号)characters in a string:

```c++
string s("Hello World!!!");
decltype(s.size()) punct_cny = 0;
for (auto c : s)
  if(ispunct(c)) ++punct_cnt;
cout << punct_cnt << " punctuation characters in " << s << endl;
// 3 punctuation characters in Hello World!!!
```

**cctype Functions:**

| `isalnum(c)`  | cctype Functions                                             |
| ------------- | ------------------------------------------------------------ |
| `isalpha(c)`  | true if c is a letter.                                       |
| `iscntrl(c)`  | true if c is a control character.                            |
| `isdigit(c)`  | true if c is a digit.                                        |
| `isgraph(c)`  | true if c is not a space but is printable.                   |
| `islower(c)`  | true if c is a lowercase letter.                             |
| `isprint(c)`  | true if c is a printable character (i.e., a space or a character that has a visible representation). |
| `ispunct(c)`  | true if c is a punctuation character (i.e., a character that is not a control character, a digit, a letter, or a printable whitespace). |
| `isspace(c)`  | true if c is whitespace (i.e., a space, tab, vertical tab, return, newline, or formfeed). |
| `isupper(c)`  | true if c is an uppercase letter.                            |
| `isxdigit(c)` | trueifcisahexadecimaldigit.                                  |
| `tolower(c)`  | If c is an uppercase letter, returns its lowercase equivalent; otherwise returns c unchanged. |
| `toupper(c)`  | If c is a lowercase letter, returns its uppercase equivalent; otherwise returns c unchanged. |

## Processing Only Some Characters?

A range for works well when we need to process every character. However, some- times we need to access only a single character or to access characters until some condition is reached. For example, we might want to capitalize only the first char- acter or only the first word in a string.

There are two ways to access individual characters in a string: We can use a subscript or an iterator.

The subscript(下标) operator (the [] operator) takes a string::size_type (§ 3.2.2, p. 88) value that denotes the position of the character we want to access. **The operator returns a reference to the character at the given position.**

The value in the subscript is referred to as “a subscript” or “an index.” The index we supply can be any expression that yields an integral value. However, **if our index has a signed type, its value will be converted to the unsigned type that string::size_type represents (§ 2.1.2, p. 36).**

Any time we use a subscript, we must ensure that there is a value at the given location.

## Library vector Type

**A vector is a collection of objects, all of which have the same type.** Every object in the collection has an associated index, which gives access to that object. A vector is often referred to as a container because it “contains” other objects. 

How we specify the information is always the same: We supply it inside a pair of angle brackets following the template’s name.

In the case of vector, the additional information we supply is the type of the objects the vector will hold:

```c++
vector<int> ivec; // ivec holds objects of type int
vector<Sales_item> Sales_vec; // holds Sales_items
vector<vector<string>> file; // vector whose elements are vectors
```

**vector is a template, not a type. Types generated from vector must include the element type, for example, vector<int>.**

## Defining and Initializing vectors

As with any class type, the vector template controls how we define and initialize vectors. Table 3.4 (p. 99) lists the most common ways to define vectors.

We can default initialize a vector (§ 2.2.1, p. 44), which creates an empty vector of the specified type:

```c++
vector<string> svec; // default initialization; svec has no elements
vector<int> ivec; // initially empty
vector<int> ivec2(ivec); // copy elemets of ivec into ivec2
vector<int> ivec3 = ivec; //  copy elemets of ivec into ivec3
vector<string> svec(ivec2); // error: svec holds strings, not ints
```

Another way to provide element values, is that under the new standard, we can list initialize (§ 2.2.1, p. 43) a vector from a list of zero or more initial element values enclosed in curly braces:

```c++
vector<string> articles = {"a", "an", "the"};
```

We can also initialize a vector from a count and an element value. The count de- termines how many elements the vector will have; the value provides the initial value for each of those elements:

```c++
vector<int> ivec(10, -1); // ten int elements, each initialized to -1
vector<string> svec(10, "hi"); // ten strings; each element is "hi"
```

We can usually omit the value and supply only a size. In this case the library cre- ates a **value-initialized** element initializer for us. This library-generated value is used to initialize each element in the container. The value of the element initializer depends on the type of the elements stored in the vector.

If the vector holds elements of a built-in type, such as int, then the element initializer has a value of 0. If the elements are of a class type, such as string, then the element initializer is itself **default initialized:**

```c++
vector<int> ivec(10); // ten elements, each initialized to 0
vector<string> svec(10); // ten elements, each an empty string
```

There are two restrictions on this form of initialization: The first restriction is that some classes require that we always supply an **explicit initializer** (§ 2.2.1, p. 44). If our vector holds objects of a type that we cannot default initialize, then we must supply an initial element value; it is not possible to create vectors of such types by supplying only a size.



**Ways to Initialize a vector:**

| `vector<T> v1`                  | vector that holds objects of type T. Default initialization; v1 is empty. |
| ------------------------------- | ------------------------------------------------------------ |
| `vector<T> v2(v1)`              | v2 has a copy of each element in v1.                         |
| `vector<T> v2 = v1`             | Equivalent to v2(v1), v2 is a copy of the elements in v1.    |
| `vector<T> v3(n, val)`          | v3 has n elements with value val.                            |
| `vector<T> v4(n)`               | v4 has n copies of a value-initialized object.               |
| `vector<T> v5{a, b, c...}`      | v5 has as many elements as there are initializers; elements are initialized by corresponding initializers. |
| `vector<T> v5 = {a, b, c ... }` | Equivalent to v5{a,b,c . . . }.                              |

## List Initializer or Element Count?

In a few cases, what initialization means depends upon whether we use curly braces or parentheses to pass the initializer(s).

```c++
vector<int> v1(10); // v1 has ten elements with value 0
vector<int> v2{10}; // v2 has one element with value 0
vector<int> v3{10, 1}; // v3 has ten elements with value 1
vector<int> v4{10, 1}; // v4 has two elelmets with value 10 and 1
```

When we use parentheses, we are saying that the values we supply are to be used to construct the object. Thus, v1 and v3 use their initializers to determine the vector’s size, and its size and element values, respectively.

On the other hand, if we use braces and there is no way to use the initializers to list initialize the object, then those values will be used to construct the object.

```c++
vector<string> v5{"hi"}; // list initialization: v5 has one element
vector<string> v6("hi"); // error: can't construct a vector from a string literal
vector<string> v7{10}; // v7 has ten default-initialized elements
vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"
```

## Adding Elements to a vector

As one example, if we need a vector with values from 0 to 9, we can easily use list initialization. What if we wanted elements from 0 to 99 or 0 to 999? List initialization would be too unwieldy. In such cases, it is better to create an empty vector and use a vector member named **push_back** to add elements at run time. The push_back operation takes a value and “pushes” that value as a new last element onto the “back” of the vector. For example:

```c++
vector<int> v2;
for (int i = 0; i != 100; ++i)
  v2.push_back(i); // append sequential integers to v2
// at end of loopv2has 100 elements, values0. . .99
```

**vector Operations:**

| `v.empty()`         | Returns true if v is empty; otherwise returns false.         |
| ------------------- | ------------------------------------------------------------ |
| `v.size()`          | Returns the number of elements in v.                         |
| `v.push_back(t)`    | Adds an element with valuet to end of v.                     |
| `v[n]`              | Returns a reference to the element at position n in v.       |
| `v1 = v2`           | Replaces the elements in v1 with a copy of the elements in v2. |
| `v1 = {a, b, c...}` | Replaces the elements in v1 with a copy of the elements in the comma-separated list. |
| `v1 == v2`          | v1 and v2 are equal if they have the same number of elements and each |
| `v1 != v2`          | element in v1 is equal to the corresponding element in v2.   |
| `<,<=,>,>=`         | Have their normal meanings using dictionary ordering.        |

## Introducing Iterators

Although we can use subscripts to access the characters of a string or the ele- ments in a vector, there is a more general mechanism—known as iterators—that we can use for the same purpose.

Like pointers (§ 2.3.2, p. 52), iterators give us indirect access to an object. In the case of an iterator, that object is an element in a container or a character in a string. We can use an iterator to fetch an element and iterators have operations to move from one element to another. As with pointers, an iterator may be valid or invalid. A valid iterator either denotes an element or denotes a position one past the last element in a container. All other iterator values are invalid.

## Using Iterators

Types that have iterators have members that return iterators. In particular, these types have members named begin and end. The begin member returns an iterator that denotes the first element (or first character), if there is one:

```c++
auto b = v.begin(), e = v.end(); // b and e have the same type
// b denotes the fisrt element and e denotes one past the last element in v
```

The iterator returned by **end** is an iterator positioned **“one past the end”** of the associated container (or string). This iterator denotes a **nonexistent** element **“off the end”** of the container. **It is used as a marker indicating when we have processed all the elements.**

The iterator returned by end is often referred to as the **off-the- end** iterator or abbreviated as “the end iterator.” If the container is empty, begin returns the same iterator as the one returned by end.

 **If the container is empty, the iterators returned by begin and end are equal—they are both off-the-end iterators.**

## Iterator Operations

As with pointers, **we can dereference an iterator to obtain the element denoted by an iterator.** Also, like pointers, we may dereference only a valid iterator that denotes an element (§ 2.3.2, p. 53). Dereferencing an invalid iterator or an off-the- end iterator has undefined behavior.

```c++
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
  auto it = s.begin(); // it denotes the first character in s
  *it = toupper(*it); // make that character uppercase
}
```

**Standard Container Iterator Operations**:

| `*iter*`         | Returns a reference to the element denoted by the iterator iter. |
| ---------------- | ------------------------------------------------------------ |
| `iter->mem`      | Dereferences iter and fetches the member named mem from the<br/>underlying element. Equivalent to (*iter).mem. |
| `++iter`         | Increments iter to refer to the next element in the container. |
| `--iter`         | Decrements iter to refer to the previous element in the container. |
| `iter1 == iter2` | Compares two iterators for equality(inequality).Two iterators are equal |
| `iter1 != iter2` | if they denote the same element or if they are the off-the-end iterator for<br/>the same container. |

## Moving Iterators from One Element to Another

Iterators use the increment (++) operator (§ 1.4.1, p. 12) to move from one element to the next. Incrementing an iterator is a logically similar operation to incrementing an integer. In the case of integers, the effect is to “add 1” to the integer’s value. **In the case of iterators, the effect is to “advance the iterator by one position.”**

```c++
// process characters in s until we run out of characters or we hit a whitespace
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
  *it = toupper(*it);
```

## Combining Dereference and Member Access

When we dereference an iterator, we get the object that the iterator denotes. If that object has a class type, we may want to access a member of that object.

For example, we might have a vector of strings and we might need to know whether a given element is empty. Assuming it is an iterator into this vector, we can check whether the string that it denotes is empty as follows:

```c++
(*it).empty();
```

For reasons we’ll cover in § 4.1.2 (p. 136), the parentheses in` (*it).empty() `are necessary. **The parentheses say to apply the dereference operator to it and to apply the dot operator (§ 1.5.2, p. 23) to the result of dereferencing it.** Without parentheses, the dot operator would apply to it, not to the resulting object:

```c++
(*it).empty(); // dereference it and calls the member empty on the resulting object
*it.empty(); // error: attempts to fetch the member named empty from it, but it is an iterator and has no member named empty
```

To simplify expressions such as this one, the language defines the arrow operator (the **-> operator)**. The arrow operator combines dereference and member access into a single operation. That is,` it->mem `is a synonym for `(*it).mem`.

 **For now, it is important to realize that loops that use iterators should not add elements to the container to which the iterators refer.**

## Iterator Arithmetic

Iterators for string and vector support additional operations that can move an iterator multiple elements at a time. They also support all the relational operators. These operations, which are often referred to as **iterator arithmetic**, are described in Table 3.7.

**Operations Supported by vector and string Iterators:**

| `iter + n`    `iter - n`    | Adding (subtracting) an integral value n to (from) an iterator yields an iterator that many elements forward (backward) within the container. The resulting iterator must denote elements in, or one past the end of, the same container. |
| :-------------------------- | ------------------------------------------------------------ |
| `iter1 += n`   `iter1 -= n` | Compound-assignment for iterator addition and subtraction. Assigns to iter1 the value of adding n to, or subtracting n from, iter1. |
| `iter1 - iter2`             | Subtracting two iterators yields the number that when added to the right-hand iterator yields the left-hand iterator. The iterators must denote elements in, or one past the end of, the same container. |
| `>,>=,<,<=`                 | Relational operators on iterators. One iterator is less than another if it refers to an element that appears in the container before the one referred to by the other iterator. The iterators must denote elements in, or one past the end of, the same container. |

