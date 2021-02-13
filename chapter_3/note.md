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

