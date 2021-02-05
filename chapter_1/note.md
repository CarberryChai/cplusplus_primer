# Getting Started

## Writing a single c++ program

```c++
#include <iostream>
#include <vector>
int main(int argc, char const *argv[]) {
  std::vector<std::string> vec{"hello", "carberry", "chai"};
  for (auto x : vec) std::cout << x << std::endl;
}
```

每一个c++1 program包含一个或者很多函数，其中必须包含唯一一个`main`函数。操作系统调用`main`函数来启动一个c++ program.

一个函数定义包括四个部分：

- return type （返回类型）
- Function name 
- Parameter list （参数列表，可以为空）
- Function body

上例中，函数返回类型为`int`，函数名为`main`，参数为`int`类型的argc, 以及指向`char`类型的常量指针数组 argv,用来接收命令行参数。

## Compiling and Executing Our Program

我的操作系统为macos，所以这里我用clang++编译器。

```shell
$ clang++ main.cpp
```

```c++
main.cpp:4:31: error: expected ';' at end of declaration
  std::vector<std::string> vec{"hello", "carberry", "chai"};
                              ^
                              ;
main.cpp:5:8: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]
  for (auto x : vec) std::cout << x << std::endl;
       ^
main.cpp:5:15: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
  for (auto x : vec) std::cout << x << std::endl;
              ^
2 warnings and 1 error generated.
```

报错啦，因为我们的程序用了c++11的语法，需要明确指定语言版本

```shell
$ clang++ -std=c++17 main.cpp
```

执行我们编译好的可执行文件`a.out`

```shell
$ ./a.out
hello
carberry
chai
```

我们还可以获取`main`函数返回的状态值

在UNIX系统

```shell
$ echo $?
0
```

在Windows系统

```shell
$ echo %ERRORLEVEL%
```

## Using Names from the Standard Library

`std::cout`中的`::`是作用域操作符，意思就是`cout` 是在一个叫做的`std`的`namespace`定义的。

```c++
int v1 = 0, v2 = 0;
std::cin >> v1 >> v2;
```

`std::cin >> v1 >> v2;` 读取两个用户输入的值，输入操作符`>>`和输出操作符`<<`类似，其实就是位运算操作符的右移和左移的重载。

**满足左结合律，返回左值**，等价于`(std::cin >> v1) >> v2;`

## Flow of Control

`statements`通常是按次序执行的：在一个代码块中，先执行第一句，再执行第二句，等等。

### The while Statement

​	while ( *condition* )

​				*statement*

只要给定`condition`是`true`，`while statement`会一直重复执行 `statement`

写一个简单的`sum`函数，求1到10的和

```c++
#include <iostream>
int sum() {
  int total = 0, i = 1;
  while(i <= 10) total += i++;
  return total;
}
int main() {
  std::cout << sum() << std::endl;
}
// 55
```

