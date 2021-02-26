# Functions

A function is a block of code with a name. We execute the code by calling the function. A function may take zero or more arguments and (usually) yields a result. Functions can be overloaded, meaning that the same name may refer to several different functions.

## Local static Objects

Each local **static** object is initialized before the first time execution passes through the object’s definition. Local statics are not destroyed when a function ends; they are destroyed when the program terminates.

```c++
size_t count_calls() {
  static size_t ctr = 0;
  return ++ctr;
}
int main() {
  for(size_t i = 0; i != 0; ++i)
    cout << count_calls() << endl;
}
```

**If a local static has no explicit initializer, it is value initialized (§ 3.3.1, p. 98), meaning that local statics of built-in type are initialized to zero.**

## Function Declarations

Like any other name, the name of a function must be declared before we can use it. **As with variables (§ 2.2.2, p. 45), a function may be defined only once but may be declared multiple times.**

```c++
// parameter names chosen to indicate that the iterators denote a range of values to print
void print(vector<int>::const_iterator beg,
          vector<int>::const_iterator end);
```

These **three elements—the return type, function name, and parameter types— describe the function’s interface.** They specify all the information we need to call the function. Function declarations are also known as the **function prototype**.

Recall that variables are declared in header files (§ 2.6.3, p. 76) and defined in source files. For the same reasons, functions should be declared in header files and defined in source files.

**The source file that defines a function should include the header that contains that function’s declaration.** That way the compiler will verify that the definition and declaration are consistent.

## Argument Passing

Parameter initialization works the same way as variable initialization.

As with any other variable, the type of a parameter determines the interaction between the parameter and its argument. **If the parameter is a reference (§ 2.3.1, p. 50), then the parameter is bound to its argument. Otherwise, the argument’s value is copied.**

When a parameter is a **reference**, we say that its corresponding argument is **“passed by reference”** or that the function is **“called by reference.”** As with any other reference, a reference parameter is an alias for the object to which it is bound; that is, the parameter is an alias for its corresponding argument.

**When the argument value is copied, the parameter and argument are independent objects.** We say such arguments are **“passed by value”** or alternatively that the function is **“called by value.”**

## Passing Arguments by Value

When we initialize a nonreference type variable, the value of the initializer is copied. Changes made to the variable have no effect on the initializer:

```c++
int n = 0; // ordinary variable of type int
int i = n; // i is a copy of the value in n
i = 42; // value in i is changed; n is unchanged
```

### Pointer Parameters

Pointers (§ 2.3.2, p. 52) behave like any other nonreference type. When we copy a pointer, the value of the pointer is copied.

```c++
int n = 0, i = 42;
int *p = &n, *q = &i; // p points to n; q points to i
*p = 42; // value in n is changed; p is unchanged
p = q; // p now points to i; values in i and n are unchanged
```

## Passing Arguments by Reference

As with any other reference, a reference parameter is bound directly to the object from which it is initialized.

```c++
void reset(int &i) {
  i = 0;
}
```

It can be inefficient to copy objects of large class types or large containers. More- over, some class types (including the IO types) cannot be copied. Functions must use reference parameters to operate on objects of a type that cannot be copied.

## const Parameters and Arguments

a top-level const is one that applies to the object itself:

```c++
const int ci = 42; // we cannot change ci; const is top-level
int i = ci; // ok: when we copy ci, its top-level const is ignored
int * const p = &i; // const is top-level; we can't assign to p
*p = 0; // ok: changes through p are allowed; i is now 0
```

Just as in any other initialization, when we copy an argument to initialize a param- eter, top-level consts are ignored.

**The fact that top- level consts are ignored on a parameter has one possibly surprising implication:**

```c++
void fcn(const int i) { // fcn can read but not write to i
  // ...
}
void fcn(int i) { // error: redefines fcn(int)
  // ...
}
```

In C++, we can define several different functions that have the same name. How- ever, we can do so only if their parameter lists are sufficiently different**. Because top-level consts are ignored, we can pass exactly the same types to either version of fcn.** **The second version of fcn is an error.** Despite appearances, its parameter list doesn’t differ from the list in the first version of fcn.

### Pointer or Reference Parameters and const

Because parameters are initialized in the same way that variables are initialized, it can be helpful to remember the general initialization rules. **We can initialize an object with a low-level const from a nonconst object but not vice versa, and a plain reference must be initialized from an object of the same type.**

```c++
int i = 42;
const int *cp = &i; // ok: but cp can't change i
const int &r = i; // ok: but r can't change i
const int &r2 = 42; // ok
int *p = cp; // error: types of p and cp don't match
int &r3 = r; // error: types of r3 and r don't match
int &r4 = 42; // error: can't initialize a plain reference from a literal
```

## Array Parameters

Arrays have two special properties that affect how we define and use functions that operate on arrays: **We cannot copy an array (§ 3.5.1, p. 114), and when we use an array it is (usually) converted to a pointer (§ 3.5.3, p. 117).** **Because we cannot copy an array, we cannot pass an array by value. Because arrays are converted to pointers, when we pass an array to a function, we are actually passing a pointer to the array’s first element.**

```c++
// despite appearances, these three declarations of print are equivalent
// each function has a single parameter of type const int*
void print(const int*);
void print(const int[]); // show the intent that the function takes an array
void print(const int[10]); // diension for documentation purposes(at best)
```

## main:Handling Command-Line Options

For example, assuming our main program is in an executable file named `prog`, we might pass options to the program as follows:

```shell
prog -d -o ofile data0
```

Such command-line options are passed to main in two (optional) parameters:

```c++
int main(int argc, char *argv[]) {}
```

**The second parameter, argv, is an array of pointers to C-style character strings.** The first parameter, argc, passes the number of strings in that array.

Because the second parameter is an array, we might alternatively define main as

```c++
int main(int argc, char **argv) {}
```

en the previous command line, `argc` would be 5, and argv would hold the following C-style character strings:

```c++
argv[0] = "prog";
argv[1] = "-d";
argv[2] = "-o";
argv[3] = "ofile";
argv[4] = "data0";
```

## Functions with Varying Parameters

Sometimes we do not know in advance how many arguments we need to pass to a function.

The new standard provides two primary ways to write a function that takes a varying number of arguments:

**If all the arguments have the same type, we can pass a library type named `initializer_list`.**

 If the argument types vary, we can write a special kind of function, known as a variadic template, which we’ll cover in § 16.4 (p. 699).

An `initializer_list` is a library type that represents an array (§ 3.5, p. 113) of values of the specified type. 

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/c9MgTV-si5L6u.png" style="zoom:50%;" />

**Unlike vector, the elements in an initializer_list are always const val- ues; there is no way to change the value of an element in an initializer_list.**

We can write our function to produce error messages from a varying number of arguments as follows:

```c++
void error_msg(initializer_list<string> il) {
  for (auto beg = il.begin(); beg != il.end(); ++beg)
    cout << *beg << " ";
  cout << endl;
}
```

When we pass a sequence of values to an initializer_list parameter, we must enclose the sequence in curly braces:

```c++
// expected, actual are strings
if (expected != actural)
  error_msg({"functionX", expected, actual});
else
  error_msg({"functionX", "okay"});
```

## Never Return a Reference or Pointer to a Local Object

**When a function completes, its storage is freed (§ 6.1.1, p. 204). After a function terminates, references to local objects refer to memory that is no longer valid:**

```c++
const string &manip() {
  string ret;
  // transform ret in some way
  if (!ret.empty())
    return ret; // WRONG: returning a reference to a local object!
  return "Empty"; // WRONG: "Empty" is a local temporary string
}
```

**The storage in which the temporary resides is freed when the function ends. Both returns refer to memory that is no longer available.**

**For the same reasons that it is wrong to return a reference to a local object, it is also wrong to return a pointer to a local object. Once the function completes, the local objects are freed. The pointer would point to a nonexistent object.**

## Functions That Return Class Types and the Call Operator

Like any operator the call operator has associativity and precedence (§ 4.1.2, p. 136). **The call operator has the same precedence as the dot and arrow operators (§ 4.6, p. 150).** **Like those operators, the call operator is left associative. As a result, if a function returns a pointer, reference or object of class type, we can use the result of a call to call a member of the resulting object.**

```c++
// call the size member of the string returned by shorterString
auto sz = shorterString(s1, s2).size();
```

## List Initializing the Return Value

Under the new standard, functions can return a braced list of values.

As an example, recall the error_msg function from § 6.2.6 (p. 220). That func- tion took a varying number of string arguments and printed an error message composed from the given strings. Rather than calling error_msg, in this func- tion we’ll return a vector that holds the error-message strings:

```c++
vector<string> process() {
  if (expected.empty())
    return {};
  else if (expected == actual)
    return {"functionX", "okay"};
  else return {"functionX", expected. actual};
}
```

In a function that returns a built-in type, a braced list may contain at most one value, and that value must not require a narrowing conversion (§ 2.2.1, p. 43). **If the function returns a class type, then the class itself defines how the intiailizers are used (§ 3.3.1, p. 99).**

## Declaring a Function That Returns a Pointer to an Array

**Because we cannot copy an array, a function cannot return an array.** However, a function can return a pointer or a reference to an array (§ 3.5.1, p. 114).

```c++
int arr[10]; // arr is an array of ten ints
int *p1[10]; // p1 is an array of ten pointers
int (*p2)[10] = f&arr; // p2 points to an array of ten ints
```

**As with these declarations, if we want to define a function that returns a pointer to an array, the dimension must follow the function’s name.**  However, a function includes a parameter list, which also follows the name. The parameter list precedes the dimension. Hence, the form of a function that returns a pointer to an array is:

`Type (*function(parameter_list))[dimension]`

As a concrete example, the following declares func without using a type alias:

```c++
int (*func(int i))[10];
```

Under the new standard, another way to simplify the declaration of `func` is by us- ing a **trailing return type.** **Trailing returns can be defined for any function, but are most useful for functions with complicated return types, such as pointers (or references) to arrays.** A trailing return type follows the parameter list and is preceded by `->`. To signal that the return follows the parameter list, we use `auto` where the return type ordinarily appears:

```c++
// func takes an int argument and returns a pointer to an array of ten ints
auto func(int i) -> int(*)[10];
```

