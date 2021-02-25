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

