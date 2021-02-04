# Chapter One Exercise

# 1.2

>Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

```c++
#include <iostream>
int main() {
  std::cout << "hello world!" << std::endl;
  return -1;
}
```

```shell
hello world!
Process finished with exit code 255
```

