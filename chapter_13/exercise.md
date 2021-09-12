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

## 13.5

> given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new string and copy the object to which ps points, rather than copying ps itself.

```c++
class HasPtr {
  public:
  	HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) {}
  	// copy constructor
  	HasPtr(const HasPtr &org):ps(new string(*org.ps)), i(org.i) {}
  private:
  	std::string *ps;
  	it i;
}
```

## 13.8

> Write the assignment operator for the HasPtr class from exercise 13.5 . As with the copy constructor, your assignment operator should copy the object to which ps points.

```c++
class HasPtr {
  public:
  	HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) {}
  	// copy constructor
  	HasPtr(const HasPtr &org):ps(new string(*org.ps)), i(org.i) {}
  	HasPtr& operator=(const HasPtr &rhs){
      delete ps;
      ps = new std::string(*rhs.ps);
      i = rhs.i;
      return *this;
    }
  private:
  	std::string *ps;
  	it i;
}
```

## 13.11

> Add a destructor to your HasPtr class from the previous exercises.

```c++
class HasPtr {
  public:
  	HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) {}
  	// copy constructor
  	HasPtr(const HasPtr &org):ps(new string(*org.ps)), i(org.i) {}
  	HasPtr& operator=(const HasPtr &rhs){
      delete ps;
      ps = new std::string(*rhs.ps);
      i = rhs.i;
      return *this;
    }
  	~HasPtr(){
      delete ps;
    }
  private:
  	std::string *ps;
  	it i;
}
```

## 13.12

> How many destructor calls occur in the following code fragment ?

```c++
bool fcn(const Sales_data *trans, Sales_data accum) {
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
}
```

3 times. `accum` 、`item1`、`item2`

## 13.13

> a good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:
>
> ```c++
> struct X {
>   X() {std::cout<< "X()" << std::endl;}
>   X(const X&) {std::cout << "X(const X&)" << std::endl;}
> };
> ```
>
> Add the copy-assignment operator and destructor to X and write a program using X objects in various ways: pass them as nonreference and reference parameters; dynamically allocate them; put them in container; and so forth. Study the output until you are certain you understand when and why each copy-control member is used. As you read the output, remember that the compiler can omit call to the copy constructor.

[code](./exercise13_13.cpp)

