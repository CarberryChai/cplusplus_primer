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

## 4.17

> Explain the difference between prefix and postfix increment.

 This prefix operators increment (or decrement) its operand and yields the changed object as its result. The postfix operators increment (or decrement) the operand but yield a copy of the original, unchanged value as its result.

## 4.18

> What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?

```c++
std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
auto it = vec.begin();
while (it != vec.end()) std::cout << *++it << " ";
```

Print `2 3 4 5 6 7 8 9 0 `, it will print from the second element and print `vec.end()`, which is undefined behaviour.

## 4.19

> Given that ptr points to an int, that vec is a vector<int>, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?

```c++
ptr != 0 && *ptr++; // check out ptr is not a nullptr; and then check value the pointer points
ival++ && ival; // check ival whether eaual to zero and do the same after ival+1
vec[ival++] <= vec[ival];
```

The last is undefined behavior.

`vec[ival] <= vec[ival+1];`

## 4.20

> Assuming that iter is a vector<string>::iterator, indicate which, if any, of the following expressions are legal. Explain the behavior of the le- gal expressions and why those that aren’t legal are in error.

```c++
*iter++; // legal; fetch the *iter and then iter++
(*iter)++; // illegal; 后置递增运算符不能作用域string
*iter.empty(); // illegal; iter 是一个迭代器对象没有empty成员函数，改为：(*iter).empty()
iter->empty(); // legal; 判断字符串是否为空
++*iter; // illegal;前置递增运算符++和dereference运算符*有相同的优先级，都是满足右结合律，相当于++(*iter),但字符串没有++操作
iter++->empty();// return iter->empty(), then ++iter.
```

## 4.21

> Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.

[code](./exercise4_21.cpp)

## 4.22

> Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?

[code](./exercise4_22.cpp)

## 4.23

> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
>
> ```c++
> string s = "word";
> string pl = s + s[s.size() -1] == 's' ? "" : "s";
> ```

The `?:` precedence is lower then `+`;

fixed:

`string pl = s = (s[s.size() - 1] == 's' ? "" : "s")`;

## 4.24

> Our program that distinguished between high pass, pass, and fail de- pended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

 if the operator were left associative:

```c++
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

## 4.25

> What is the value of ~’q’ << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which ’q’ has the bit pattern 01110001?

```c++
int x = 0b10001110000000;
```

## 4.26

> In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

The C++ standard does not specify the size of integral types in bytes, but it specifies minimum ranges they must be able to hold. The minimum range of `unsigned int` is 0 to 65535. Since some implementations use only the minimum 16 bits for `unsigned int`, this could cause undefined behavior.

## 4.27

> What is the result of each of these expressions?

```c++
unsigned long ul1 = 3, ul2 = 7;
ul1 & ul2; // 3
ul1 | ul2; // 7
ul1 && ul2; // true
ul1 || ul2; // true
```

## 4.28

> Write a program to print the size of each of the built-in types.

[code](./exercise4_28.cpp)

## 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.

```c++
int x[10]; int *p = x;
cout << sizeof(x) / sizeof(*x) << endl; // 10
cout << sizeof(p) / sizeof(*p) << endl; // undefined behavior
```

## 2.30

> Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:

```c++
sizeof x +y; // sizeof(x) + y; sizeof优先级大于+
sizeof p->mem[i]; // sizeof((p->mem)[i])
sizeof a < b; // sizeof(a) < b
sizeof f(); // sizeof (f())
```

## 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

------



> **Advice: Use Postfix Operators only When Necessary**

> Readers from a C background might be surprised that we use the prefix increment in the programs we've written. The reason is simple: The prefix version avoids unnecessary work. It increments the value and returns the incremented version.The postfix operator must store the original value so that it can return the unincremented value as its result. If we don’t need the unincremented value, there’s no need for the extra work done by the postfix operator.

> For ints and pointers, the compiler can optimize away this extra work. For more complicated iterator types, this extra work potentially might be more costly. By habitually using the prefix versions, we do not have to worry about whether the performance difference matters. Moreover—and perhaps more importantly—we can express the intent of our programs more directly.

Make no change to use the postfix version

Rewrite the program:

```c++
vector<int>::size_type cnt = ivec.size();
for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
  ivec[ix] = cnt;
```

## 4.32

> Explain the following loop.

```c++
constexpr int size = 5;
int ia[size] = {1, 2, 3, 4, 5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++iz, ++ptr){
  // ....
}
```

The pointer `ptr` and index `ix` have the same function.

## 4.33

> Using Table 4.12 (p. 166) explain what the following expression does:

```c++
someValue ? ++x, ++y : --x, --y; 
// 如果 someValue 为 true，x, y 都加1，返回y
```

## 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions:

```c++
if(fval) // fval converted to bool
dval = fval + ival;// ival converted to float, the result of the addition converted to double
 dval + ival * cval; // cval converted to int, then that int and ival converted to double.
```

## 4.35

> Given the following definitions,
>
> ```c++
> char cval; int ival; unsigned int ui; 
> float fval; double dval;
> ```
>
> identify the implicit type conversions, if any, taking place:

```c++
cval = 'a' + 3; // the literal char 'a' converted to int,and then the result converted to char
fval = ui - ival * 1.0; // ival converted to double, ui converted to double, then  that double converted(by truncation) to float.
dval = ui * fval; // ui promoted to float, and then float converted to double
cval = ival + fval + dval; // ival converted to float, and then that float converted to double, and then converted to char
```

## 4.36

> Assuming i is an int and d is a double write the expression i *= d so that it does integral, rather than floating-point, multiplication.

```c++
i *= static_cast<int>(d);
```

## 4.37

> Rewrite each of the following old-style casts to use a named cast:

```c++
int i; double d; const string *ps; char *pc; void *pv;
pv = static_cast<void*>(const_cast<string*>(ps));
i = static_cast<ibnt>(*pc);
pv = static_cast<void*>(&d);
pc = static_cast<char*>(pv);
```

## 4.38

> Explain the following expression:

```c++
double slope = static_cast<double>(j/i);
```

`j/i `is an int(by truncation), then converted to double and assigned to slope.

