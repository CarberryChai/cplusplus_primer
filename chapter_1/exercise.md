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

# 1.3

> Write a program to print Hello, World on the standard output.

```c++
#include <iostream>
int main() {
  std::cout << "Hello, World" << std::endl;
}
```

# 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```c++
#include <iostream>

int main() {
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "v1 = " << v1 << "; v2 = " << v2 << "; product is " << v1 * v2
            << std::endl;
  return 0;
}
```

## 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```c++
#include <iostream>

int main() {
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "v1 = " <<std::endl;
  std::cout << v1 << std::endl
  std::cout << "v2 = " << std::endl;
  std::cout << v2 << std::endl;
  std::cout << "product is " << std::endl;
  std::cout << v1 * v2 << std::endl;
  return 0;
}
```

## 1.6

> Explain whether the following program fragment is legal.
> std::cout << "The sum of " << v1; 
>
> ​				<< " and " << v2;
> ​                << " is " << v1 + v2 << std::endl;
> If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

上面的代码有三个分号表示三个语句，第一个语句显然是合法的，第二，三个语句非法，`<<`输出操作符左操作对象必须是一个`ostream`对象。可以改为

```c++
std::cout << "The sum of " << v1
  				<< " and " << v2
  				<< " is " << v1 + v2 << std::endl;

```

去掉分号，或者：

```c++
std::cout << "The sum of " << v1; 
std::cout << " and " << v2;
std::cout << " is " << v1 + v2 << std::endl;

```

