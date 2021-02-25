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

