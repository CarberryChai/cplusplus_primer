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

至于为啥退出码是255呢？查看[Exit Codes With Special Meanings](https://tldp.org/LDP/abs/html/exitcodes.html)

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

## 1.8

> Indicate which, if any, of the following output statements are legal:
>
> ```c++
> std::cout << "/*";
> std::cout << "*/";
> std::cout << /* "*/" */;
> std::cout << /* "*/" /* "/*" */;
> ```
>
> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

第三个打印语句不合法

```c++
std::cout << /* "*/" */; // 不合法
```

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/79SqdE-8VxYou.png" style="zoom:50%;" />

至于上面什么是`valid pp token`，可以点击查看[连接](https://stackoverflow.com/questions/31320515/what-are-the-definitions-for-valid-and-invalid-pp-tokens)

## 1.9

> Write a program that uses a while to sum the numbers from 50 to 100.

[answer](./exercise1_9.cpp)

## 1.10

> In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.

[answer](./exercise1_10.cpp)

## 1.11

> Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

[answer](./exercise1_11.cpp)

## 1.12

> What does the following for loop do? What is the final value of sum?
>
> ```c++
> int sum = 0;
> for(int i = -100; i <= 100; ++i)
>   sum += i;
> ```

这个`for` loop 是在求-100到100之间整数的和， 结果为0；

## 1.13

> Rewrite the first two exercises from § 1.4.1 (p. 13) using for loops.

### 1.9

```c++
#include <iostream>
int main() {
  int total = 0;
  for(int i = 50; i <= 100; ++i)
    total += i;
  std::cout << "result is : " << total << std::endl;
}
```

### 1.10

```c++
#include <iostream>
int main() {
  for(int i = 10; i >= 0; --i)
    std::cout << i << std::endl;
}
```

## 1.14

> Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?

查看 [stack overflow](https://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

## 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

```c++
#include <iostream>
int sum (int a, int b) {
  return a + b;
}
int main() {
  std::cout << "hello, world!" << std::endl // syntax errors: missing ;
  int result = sum(1, '2') // Type errors
  std::cout << "Result is : " << reasult << std::endl; // Declaration errors, spelling error, reasult is not defined
}
```

## 1.16

> Write your own version of a program that prints the sum of a set of integers read from cin.

[answer](./exercise1_16.cpp)