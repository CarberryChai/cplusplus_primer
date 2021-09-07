# Expressions

An **expression** is composed of one or more operands and yields a result when it is evaluated.

## Basic Concepts

There are both **unary operators** (一元操作符) and **binary operators**（二元操作符）. Unary operators, such as address-of (&) and dereference (*), act on one operand. Binary operators, such as equality (==) and multiplication (*), act on two operands. 

Some symbols, such as *, are used as both a unary (dereference) and a bi- nary (multiplication) operator. The context in which a symbol is used determines whether the symbol represents a unary or binary operator. The uses of such sym- bols are independent; it can be helpful to think of them as two different symbols.

## Overloaded Operators

The language defines what the operators mean when applied to built-in and com- pound types. We can also define what most operators mean when applied to class types. Because such definitions give an alternative meaning to an existing opera- tor symbol, we refer to them as **overloaded operators**. The IO library >> and << operators and the operators we used with strings, vectors, and iterators are all overloaded operators.

When we use an overloaded operator, **the meaning of the operator—including the type of its operand(s) and the result—depend on how the operator is defined.** **However, the number of operands and the precedence and the associativity of the operator cannot be changed.**（操作符的意义可以改变，操作符的操作对象的数量以及优先级和结合律是不变的。）

## Lvalues and Rvalues

In C++, the distinction is less simple. In C++, an lvalue expression yields an object or a function. However, some lvalues, such as const objects, may not be the left-hand operand of an assignment. Moreover, some expressions yield objects but return them as rvalues, not lvalues. **Roughly speaking, when we use an object as an rvalue, we use the object’s value (its contents). When we use an object as an lvalue, we use the object’s identity (its location in memory).** (概括来说，当我们用一个对象作为右值，我们用的是这个对象的值，也就是它的内容。当我们用一个对象作为左值，我们用的是这个对象的标识，也就是它在内存中的位置)

**The important point is that (with one exception that we’ll cover in § 13.6 (p. 531)) we can use an lvalue when an rvalue is required, but we cannot use an rvalue when an lvalue (i.e., a location) is required. When we use an lvalue in place of an rvalue, the object’s contents (its value) are used. We have already used several operators that involve lvalues.**

- Assignment requires a (nonconst )lvalue as its left-hand operand and yields its left-hand operand as an lvalue.
- The address-of operator (§ 2.3.2, p. 52) requires an lvalue operand and returns a pointer to its operand as an rvalue.
- **The built-in dereference and subscript operators (§ 2.3.2, p. 53, and § 3.5.2, p. 116) and the iterator dereference and string and vector subscript operators (§ 3.4.1, p. 106, § 3.2.3, p. 93, and § 3.3.3, p. 102) all yield lvalues.**
- The built-in and iterator increment and decrement operators (§ 1.4.1, p. 12, and § 3.4.1, p. 107) require lvalue operands and the prefix versions (which are the ones we have used so far) also yield lvalues.

**Lvalues and rvalues also differ when used with decltype (§ 2.5.3, p. 70). When we apply decltype to an expression (other than a variable), the result is** **a reference type if the expression yields an lvalue.**

As an example, assume `p` is an `int`*. Because **dereference yields an lvalue**,` decltype(*p)` is` int&`. On the other hand, because the address-of operator yields an rvalue, `decltype(&p)` is `int**`, that is, a pointer to a pointer to type int.

## Arithmetic Operators

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/M7K2lr-qMSdcc.png" style="zoom:50%;" />

Unless noted otherwise, the arithmetic operators may be applied to any of the arithmetic types (§ 2.1.1, p. 32) or to any type that can be converted to an arithmetic type. **The operands and results of these operators are rvalues.** As described in § 4.11 (p. 159), **operands of small integral types are promoted to a larger integral type, and all operands may be converted to a common type as part of evaluating these operators.**

## The Relational Operators

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/j475jZ-Nmf6lk.png" style="zoom:50%;" />

The relational operators (<, <=, >, <=) have their ordinary meanings and return bool values. These operators are **left associative**.(并且具有相同的优先级)

**Because the relational operators return bools, the result of chaining these op- erators together is likely to be surprising:**

```c++
// oops! this condition compares k to the bool result of i < j
if (i < j < k) // true if k is greater than 1
```

This condition groups i and j to the first < operator. The bool result of that expression is the left-hand operand of the second less-than operator. **That is, k is compared to the true/false result of the first comparison!** (Ps: 之前确实在这个地方掉了坑 :disappointed_relieved:)To accomplish the test we intended, we can rewrite the expression as follows:

```c++
if (i < j && j < k) // ok: condition is true if i is smaller than j and j is smaller than k
```

If we want to test the truth value of an arithmetic or pointer object, the most direct way is to use the value as a condition:

```c++
if(val) {} // true if val is any nonzero value
if(!val) {} // true if val is zero
```

We might think we could rewrite a test of this kind as

```c++
if (val == true) {} // true only if val is equal to 1
```

**If val is not a bool, then true is converted to the type of val before the == operator is applied. That is, when val is not a bool, it is as if we had written**

```c++
if (val == 1) {}
```

## Assignment Operators

The left-hand operand of an assignment operator must be a modifiable lvalue（赋值运算符的左手操作对象必须是一个可修改的左值）. For example, given

```c++
int i = 0, j = 0, k = 0; // initializations, not assignment
const in ci = i; // initializations, not assignment
```

Each of these assignments is illegal:

```c++
1024 = k; // error: literals are rvalues
i + j = k; // error: arithmetic expressions are rvalues
ci = k; // error: ci is a const(nonmodifiable) lvalue
```

**The result of an assignment is its left-hand operand, which is an lvalue. The type of the result is the type of the left-hand operand**. If the types of the left and right operands differ, the right-hand operand is converted to the type of the left:

```c++
k = 0; // result: type int, value 0
k = 3.14159; // result: type int, value 3
```

Under the new standard, we can use a braced initializer list (列表初始化)(§ 2.2.1, p. 43) on the right-hand side:

```c++
k = {3.14}; // error: narrowing conversion
vector<int> vi; // initially empty
vi = {0,1,2,3,4,5,6,7,8,9}; // vi now has ten elements, values 0 through 9
```

**If the left-hand operand is of a built-in type, the initializer list may contain at most one value, and that value must not require a narrowing conversion (§ 2.2.1, p. 43).**

Regardless of the type of the left-hand operand, the initializer list may be empty. In this case, the compiler generates a value-initialized (§ 3.3.1, p. 98) temporary and assigns that value to the left-hand operand.

## Increment and Decrement Operators

The increment (++) and decrement (--) operators provide a convenient notational shorthand for adding or subtracting 1 from an object.

 **This prefix operators increment (or decrement) its operand and yields the changed object as its result. The postfix operators increment (or decrement) the operand but yield a copy of the original, unchanged value as its result:**

```c++
int i = 0, j;
j = ++i; // j = 1, i = 1; prefix yields the incremented value
j = i++; // j = 1, i = 2; postfix yields the unincremented value
```

These operators require lvalue operands. **The prefix operators return the object itself as an lvalue.** **The postfix operators return a copy of the object’s original value as an rvalue.**

## Combining Dereference and Increment in a Single Expression

```c++
auto pbeg = v.begin();
while(pbeg != v.end() && *pbeg >= 0)
  cout << *pbeg++ <<endl; // print the current value and advance pbeg
```

The precedence of postfix increment is higher than that of the dereference operator, so `*pbeg++` is equivalent to `*(pbeg++)`.

## The Bitwise Operators

The bitwise operators take operands of integral type that they use as a collection of bits.

<img src="https://cdn.jsdelivr.net/gh/CarberryChai/oss@master/image/8DPiEq-zXmCHe.png" style="zoom:50%;" />

**If the operand is signed and its value is negative, then the way that the “sign bit” is handled in a number of the bitwise operations is machine dependent. Moreover, doing a left shift that changes the value of the sign bit is undefined.**

 **Because there are no guarantees for how the sign bit is handled, we strongly recommend using unsigned types with the bitwise operators.**

## The sizeof Operator

The `sizeof` operator returns the size, in bytes, of an `expression` or a `type` name. The operator is right associative. The result of sizeof is a` constant expression` (§ 2.4.4, p. 65) of type `size_t` (§ 3.5.2, p. 116). The operator takes one of two forms:

`sizeof (type)`

`sizeof expr`

```c++
Sales_data data, *p;
sizeof (Sales_data); // size required to hold an object of type Sales_data
sizeof (data); // size of data's type, i.e., sizeof(Sales_data)
sizeof (p); // size of a pointer
sizeof (*p); // size of the type to which p points, i.e., sizeof(Sales_data)
sizeof data.revenue; // size of the type of Sales_data's revenue member
sizeof Sales_data::revenue; // alternative way to get the size of revenue
```

The most interesting of these examples is `sizeof *p`. First, because `sizeof` is right associative and has the same precedence as`*` *, this expression groups right to left. That is, it is equivalent to `sizeof (*p)`. **Second, because `sizeof` does not evaluate its operand, it doesn’t matter that p is an invalid (i.e., uninitialized) pointer (§ 2.3.2, p. 52).** **Dereferencing an invalid pointer as the operand to sizeof is safe because the pointer is not actually used. sizeof doesn’t need dereference the pointer to know what type it will return.**

## Array to Pointer Conversions

**In most expressions, when we use an array, the array is automatically converted to a pointer to the first element in that array:**

```c++
int ia[10]; // array of ten ints
int *ip = ia; // convert ia to a pointer to the first element
```

**This conversion is not performed when an array is used with `decltype` or as the operand of the address-of (`&`), `sizeof`, or `typeid` (which we’ll cover in § 19.2.2 (p. 826)) operators. The conversion is also omitted when we initialize a reference to an array (§ 3.5.1, p. 114). As we’ll see in § 6.7 (p. 247), a similar pointer conversion happens when we use a function type in an expression.**

## Explicit Conversions

A named cast has the following form:

cast-name<type> (expression);

where type is the target type of the conversion, and expression is the value to be cast. If type is a reference, then the result is an lvalue. The cast-name may be one of `static_cast`, `dynamic_cast`, `const_cast`, and `reinterpret_cast`.

### `static_cast`

**Any well-defined type conversion, other than those involving low-level const, can be requested using a static_cast.** For example, we can force our expression to use floating-point division by casting one of the operands to double:

```c++
int i, j;
double slope = static_cast<double>(j) / i;
```

A static_cast is often useful when a larger arithmetic type is assigned to a smaller type. 

A static_cast is also useful to perform a conversion that the compiler will not generate automatically. For example, we can use a static_cast to retrieve a pointer value that was stored in a void* pointer (§ 2.3.2, p. 56):

```c++
void* p = &d; // ok: address of any nonconst object can be stored in a void*
double *dp = static_cast<double*>(p); // ok: converts void* back to the original pointer type
```

### `const_cast`

A const_cast changes only a low-level (§ 2.4.3, p. 63) const in its operand:

```c++
const char *pc;
char *p = const_cast<char*>(pc); // ok: but writing through p is ndefined
```

