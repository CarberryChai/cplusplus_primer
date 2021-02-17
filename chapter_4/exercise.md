# Chapter Four Exercise

## 4.1

>  What is the value returned by 5 + 10 * 20/2?

105

## 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
>
> ```c++
> * vec.begin();
> * vec.begin() + 1;
> ```

`*((vec.begin)())`

`(*((vec.begin)()) + 1)`

## 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

No. such design cannot improve performance siginificantly, but it can make bugs very tricky to handle.

## 4.4

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.

```c++
 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```

```c++
((12 / 3) *4) + (5 * 15) + ((24 % 4) / 2)
```

91 [code](./exercise4_4.cpp)

## 4.5

> Determine the result of the following expressions.

```c++
-30 * 3 + 21 / 5; // -86
-30 + 3 * 21 / 5; // -18
30 / 3 * 21 % 5; // 0
-30 / 3 * 21 % 4; // -2
```

## 4.6

> Write an expression to determine whether an int value is even or odd.

```c++
int main() {
  int n;
  if(std::cin >> n) {
    if(n % 2 == 0) std::cout << "even" << std::endl;
    else std::cout << "odd" << std::endl;
  }
}
```

## 4.7

> What does overflow mean? Show three expressions that will overflow.

 Overflow happens when a value is computed that is outside the range of values that the type can represent.

```c++
short sv = 32727;
++sv; // -32768
unsigned short us = 0;
--us; // 65535

```

## 4.8

> Explain when operands are evaluated in the logical AND, logical OR, and equality operators.

------

> The logical AND and OR operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as short-circuit evaluation:
>
> - The right side of an && is evaluated if and only if the left side is true.
> - The right side of an || is evaluated if and only if the left side is false.

## 4.9

> Explain the behavior of the condition in the following if:

```c++
const char *cp = "Hello World";
if(cp && *cp) 
```

`cp` is a pointer to `const char*` which is not null pointer.`true`

`*cp` is char 'H' and it's explicit a nonzero value, `true`

`true && true` => `true`

## 4.10

> Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.

```c++
int x;
while(std::cin >> x && x != 42) {
}
```

## 4.11

> Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.

```c++
if(d < c && c < b && b < a)
```

## 4.12

> Assuming i, j, and k are all ints, explain what i != j < k means.

操作符`<`的优先级大于`!=`, 先判断`j < k`，其结果是`bool`值，将转化为`i`的类型int--0 or 1，所以整个表达式就是在判断`i`是否不等于0或者1

## 4.13

> What are the values of i and d after each assignment?

```c++
int i; double d;
d = i = 3.5; // i = 3, d = 3.0
i = d = 3.5; // d = 3.5, i = 3
```

## 4.14

> Explain what happens in each of the if tests:

```c++
if(42 = i) // error: can't assign i to literal
if(i = 42) // ok: i is 42 and it's nonzero
```

## 4.15

> The following assignment is illegal. Why? How would you correct it?

```c++
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

`ival` and `pi` have different types and  there is no conversion from the type of `int* `to the type of `int`.

Corrert:

```c++
pi = 0;
dval = ival = 0;
```

## 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.

```c++
if(p = getPtr() != 0) // p = true or false
if (i = 1024) // always true
```

assignment has lower precedence than the relational operators

Corrert:

```c++
if((p = getPtr()) != 0)
if(i == 1024)
```

