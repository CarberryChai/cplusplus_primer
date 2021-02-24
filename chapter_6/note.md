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

