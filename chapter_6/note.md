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