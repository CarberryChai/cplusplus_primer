

# Chapter Six Exercise

## 6.1

> What is the difference between a parameter and an argument?

Arguments are the initializers for a function’s parameters. 

**Parameters**: Local variable declared inside the function parameter list. they are initialized by the **arguments** provided in the each function call.

**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

## 6.2

> Indicate which of the following functions are in error and why. Suggest how you might correct the problems.

```c++
string f() {
  string s;
  return s;
} // the return type should be string, not int
```

------

```c++
void f2(int i) {
  // ...
} // f2 needs the return type
```

------

```c++
int calc(int v1, int v2) {
  // .. 
} // the two parameters cannot have the same name
```

------

```c++
double square(double x) {
  return x * x;
} // function body needs braces
```

## 6.3

> Write and test your own version of fact.

[code](./exercise6_3.cpp)

## 6.4

> Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.

[code](./exercise6_4.cpp)

## 6.5

> Write a function to return the absolute value of its argument.

```c++
int abs(int x) {
  return x >= 0 ? x : -x;
}
```

## 6.6

> Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.

**local variable**: Variables defined inside a **block**;

**parameter**: **Local variables** declared inside the **function parameter list**

**local static variable**: **local static variable（object）** is initialized before the first time execution passes through the object’s definition.**Local statics** are not destroyed when a function ends; they are **destroyed when the program terminates.**

## 6.7

> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

[code](./exercise6_7.cpp)

## 6.8

> Write a header file named Chapter6.h that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).

[Chapter6.h](./Chapter6.h)

## 6.9

> Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

[fact.cc](./fact.ccp)   [factMain.cpp](./factMain.cpp)

## 6.10

> Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.

[code](./exercise6_10.cpp)

## 6.11

> Write and test your own version of reset that takes a reference.

[code](./exercise6_11.cpp)

## 6.12

> Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use refer- ences instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

[code](./exercise6_12.cpp)

The reference version is easier to use.

## 6.13

> Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&).

`void f(T)` pass the argument by value

`void f(T&)`  pass the argument by reference

## 6.14

> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

a parameter should be a reference type:

```c++
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
```

a parameter should not be a reference:

```c++
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```

## 6.15

> Explain the rationale for the type of each of find_char’s parameters In particular, why is s a reference to const but occurs is a plain reference? Why are these parameters references, but the char parameter c is not? What would happen if we made s a plain reference? What if we made occurs a reference to const?

why is s a reference to const but occurs is a plain reference?

我们的意图是在字符串`s`中查找给定字符，并没有打算修改字符串`s`, 因此最好把`s`设置为 a reference to const. 至于`occurs`是一个普通reference，因为我们打算修改它的值。

 Why are these parameters references, but the char parameter c is not?

也可以设置为reference，但没必要，`char`类型所占空间很小，copy的代价很小

What would happen if we made s a plain reference? What if we made occurs a reference to const?

没变化，因为我们并没有打算修改字符串`s`，最好还是设置成 a reference to const;

如果我们把`occurs`设置为a reference to const，`occurs = 0;` would be an error;

## 6.16

> The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:

```c++
bool is_empty(const string &s) {
  return s.empty();
}
```

## 6.17

> Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

[code](./exercise6_17.cpp)

Not the same;

## 6.18

> Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.

(a) A function named compare that returns a bool and has two parameters that are references to a class named matrix.

```c++
bool compare(const matrix &m1, const matrix &m2);
```

(b) A function named change_val that returns a` vector<int>` iterator and takes two parameters: One is an int and the other is an iterator for a` vector<int>`.

```c++
vector<int>::iterator change_val(int x, vector<int>::iterator it);
```

## 6.19

> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.

```c++
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

// a
calc(23.4, 55.1); // illegal; too many arguments
// b
count("abcda", 'a'); // legal
// c
calc(66); // legal
// d
sum(vec.begin(), vec.end(), 3.8); // legal
```

## 6.20

> When should reference parameters be references to const? What hap- pens if we make a parameter a plain reference when it could be a reference to const?

------

> It is a somewhat common mistake to define parameters that a function does not change as (plain) references. Doing so gives the function’s caller the misleading impression that the function might change its argument’s value. Moreover, using a reference instead of a reference to const unduly limits the type of arguments that can be used with the function. As we’ve just seen, we cannot pass a const object, or a literal, or an object that requires conversion to a plain reference parameter.

## 6.21

> Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?

[code](./exercise6_21.cpp)

The type for the pointer is `const int*`

## 6.22

> Write a function to swap two int pointers.

[code](./exercise6_22.cpp)

## 6.23

> Write your own versions of each of the print functions presented in this section. Call each of these functions to print i and j defined as follows:
>
> ```c++
> int i = 0, j[2] = {0, 1};
> ```
>
> 

[code](./exercise6_23.cpp)

## 6.24

> Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.
>
> ```c++
> void print(const int ia[10]) {
>   for (size_t i = 0; i != 10; ++i)
>     cout << ia[i] << endl;
> }
> ```
>
> 

**Because we cannot copy an array, we cannot pass an array by value. Because arrays are converted to pointers, when we pass an array to a function, we are actually passing a pointer to the array’s first element.**

`const int ia[10]` is equivalent to `const int*`, and the size of the array is **irrelevant**. we can pass `const int ia[3]` or `const int ia[255]`, there are no differences.  If we want to pass an array with **dimension**, we should use reference like that:

```c++
void print(const int (&ia)[10]) {
  for (auto item : ia)
    cout << item << endl;
}
```

[see more](https://stackoverflow.com/questions/26530659/confused-about-array-parameters)

## 6.25

> Write a main function that takes two arguments. Concatenate the sup- plied arguments and print the resulting string.

[code](./exercise6_25.cpp)

# 6.26

is the same as 6.25

## 6.27

> Write a function that takes an initializer_list<int> and pro- duces the sum of the elements in the list.

[code](./exercise6_27.cpp)

## 6.28

>  In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?

`const string&`

## 6.29

> When you use an initializer_list in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?

Depend on whether the copied type is **cheep** or not, like `string` or any other large class type, it's better use reference, otherwise, not use

## 6.30

> Compile the version of str_subrange as presented on page 223 to see what your compiler does with the indicated errors.

- error: non-void function 'str_subrange' should return a value [-Wreturn-type]
- error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]

## 6.31

> When is it valid to return a reference? A reference to const?

" One good way to ensure that the return is safe is to ask: To what preexisting object is the reference referring?"

## 6.32

> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.
>
> ```c++
> int &get(int *arry, int index) {
>   return arry[index];
> }
> int main() {
>   int ia[10];
>   for (int i = 0; i != 10; ++i)
>     get(ia, i) = i;
> }
> ```
>
> 



Legal; give the array ia value from 0 to 9 inclusive

## 6.33

> Write a recursive function to print the contents of a vector.

[code](./exercise6_33.cpp)

## 6.34

> What would happen if the stopping condition in factorial were

```c++
if (val != 0)
```

If `val` is postive, it's ok; otherwise, if val is negative, the stopping condition will not occur.

## 6.35

>  In the call to factorial, why did we pass `val - 1` rather than `val--`?

the function will recurse “forever”.

## 6.36

> Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

```c++
string (&func())[10];
```

## 6.37

> Write three additional declarations for the function in the previous ex- ercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

```c++
using stringT = string[10];
stringT &func();
auto func() -> string(&)[10];
string s[10];
decltype(s) &func();
```

I prefer the rrailing return.

## 6.38

> Revise the arrPtr function on to return a reference to the array.

```c++
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
auto arrPtr(int i) -> int(&)[5] {
  return (i % 2) ? odd : even;
}
```

