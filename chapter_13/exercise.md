# chapter 13 Copy Control

## 13.1

> What is a copy constructor? What is it used?

> A constructor is the copy constructor if its first parameter is a reference to the class type and any additional parameters have default values

- Copy initialization (copy initialization ordinarily uses the copy constructor.)
- parameters and return values (*During a function call, parameters that have a nonreference type are copy initialized.*)

## 13.2

> Explain why the following declaration is illegal:

```c++
Sales_data::Sales_data(Sales_data rhs);
```

改为：

```c++
Sales_data::Sales_data(const Sales_data &rhs);
```

> The fact that the copy constructor is used to initialize nonreference parameters of class type explains why the copy constructor's own parameter must be a **reference**. If that parameter was not a reference, then the call would never succeed--- to call the copy constructor, we'd need to use the copy constructor to copy the argument, but to copy the argument , we'd need to call the copy constructor, and so on indefinitely.

## 13.3

> What happens when we copy a StrBlob ? What about StrBlobPtrs ?

## 13.4

> Assuming Point is class type with a public copy constructor, identify each use of the copy constructor in this program fragment:

```c++
Point global;
Point foo_bal(Point arg) {
  Point local = arg, *heap = new Point(global);
  *heap = local;
  Point pa[4] = {local, *heap};
  return *heap;
}
```