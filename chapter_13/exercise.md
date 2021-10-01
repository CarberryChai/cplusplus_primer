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
      auto temp = new std::string(*rhs.ps);
      delete ps;
      ps = temp;
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

Output:

> X()
> X(const X&)
> X(const X&)
> X(const X&)
> X(const X&)
> ~X()
> ~X()
> ~X()
> ~X()
> ~X()

## 13.14

> assume that numbered is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named mysn. Assming numbered uses the synthesized copy-control members and given the following function:
>
> ```c++
> void f (numbered s ) {
>   cout << s.mysn << endl;
> }
> ```
>
> What output does the following code produce ?
>
> ```c++
> numbered a, b = a, c = b;
> f(a);
> f(b);
> f(c);
> ```

They are the same serial number.

## 13.15

> Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise ?  If so, why ? What output gets generated ?

Yes , 

## 13.18,  13.19

> - Define a Employee class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a string representing the employee's name. Each constructor should generate a unique ID by incrementing a static data member.
> - Does your Employee class need to define its own versions of the copy-control members ? If so, why ? If not, why not ? Implement whatever copy-control members you think Employee needs.

[code](./exercise13_18_19.cpp)

## 13.20

> Explain what happens when we copy, assign, or destory objects of our TextQuery and QueryResult classs form p.484.

The smart points (shared_ptr) will be copied.

## 13.21

> Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members ? If so, why ? If not, why not ? Implement whichever copy-constrol operations you think these classes require.

no need. The  type of the members of TextQury and QueryResult is smart point, it meet all the requirement.

## 13.24

> What would happen if the version of HasPtr in this section didn't define a destructor ? what if HasPtr didn't define the copy constructor ?

It will leak the memory. The object that the member ps points will not be freed.

## 13.27

> Define your own reference-couonted version of HasPtr.

[code](./exercise13_27.cpp)

## 13.28

> Given the following classes, implement a default constructor and the necessary copy-constructor members.
>
> (a)
>
> ```c++
> class TreeNode {
>   private:
>   	std::string value;
>   	int count;
>   	TreeNode *left;
>   	TreeNode *right;
> };
> ```
>
> (b)
>
> ```c++
> class BinStrTree {
>   private:
>   	TreeNode *root;
> };
> ```

[code](exercise13_28.cpp)

## 13.33

> Why is the parameter to the save and remove members of Message a Folder& ? Why didn't we define that parameter as Folder ? or const Folder& ?

Bcz we will use Folder& to change the member of Folder.

## 13.39

> Write your own version of StrVec, including versions of reserve, capacity, and resize.

[StrVec.h](,/StrVec.h)

[StrVec.cpp](./StrVec.cpp)

## 13.40

> Add a constructor that takes an initializer_list<string> to your StrVec class.

[StrVec.h](,/StrVec.h)

[StrVec.cpp](./StrVec.cpp)

## 13.43

> rewrite the free member to use for_each and a lambda in place of the for loop to destory the elements. Which implementation do you prefer, and why ?

```c++
void StrVec::free() {
  if (elements) {
    // auto p = first_free;
    // while (p != elements) {
    //   std::allocator_traits<std::allocator<std::string>>::destroy(alloc,
    //   --p);
    // }
    std::for_each(elements, first_free, [](const std::string& s) {
      std::allocator_traits<std::allocator<std::string>>::destroy(alloc, &s);
    });
    alloc.deallocate(elements, cap - elements);
  }
}
```

I prefer the last one, it's so handy and readable.

## 13.44 or 13.47 or 13.48  or 13.49 or 13.50

> - Define a vector<String> and call push_back several times on that vector. run your program and see how often Strings are copied.
> - Put print statement in the move operations in your string class and rerun the program from exercise 13.48 that used a vector<String> to see when the copies are avoided.

[MyString.h](./MyString.h)

[MyString.cpp](./MyString.cpp)

```c++
int main() {
  std::vector<MyString> vec;
  vec.push_back("hello");
  vec.push_back("chai");
}
```



14.48

```
MyString const char constructor
MyString copy constructor is called
MyString destructor is called
MyString const char constructor
MyString copy constructor is called
MyString copy constructor is called
MyString destructor is called
MyString destructor is called
MyString destructor is called
MyString destructor is called
```

14.50

```
MyString const char constructor
MyString move constructor is called
MyString destructor is called
MyString const char constructor
MyString move constructor is called
MyString move constructor is called
MyString destructor is called
MyString destructor is called
MyString destructor is called
MyString destructor is called
```



## 13.45

> distinguish between an rvalue reference and an lvalue reference.

Definition:

- an lvalue reference is a reference that must be bound to an lvalue.
- an rvalue reference is a reference that may be bound only to an object that is about to be destroyed.

## 13.46

> Which kind of reference can be bound to the following initializers ?

```c++
int f();
vector<int> vi(100);
int &&r1 = f();
int &r2 = vi[0];
int &r3 = r1;
int &&r4 = vi[0] * f();
```

## 13.51

> although unique_ptrs cannot be copied, in 12.1.5(p. 471) we wrote a clone function that returned a unique_ptr by value. Explain why that function is legal and gow it works.

> If the class deﬁnes either a move constructor and/or a move-assignment operator, then the synthesized copy constructor and copy-assignment operator for that class will be deﬁned as deleted.

Because the function `clone` return a rvalue. the compiler knows that the object being returned is about to be destroyed. so that when we construct a new object from the return value or assign the return value to an object, we call move constructor or move-assignment operator. Thus no copy is made. the resource is moved from the return object to the new object.

## 13.52

> Explain in detail what happens in the assignments of the HasPtr objects on page 541. In particular, describe step by step what happens to values of hp. hp2, and of the rhs parameter in the HasPtr assignment operator.

## 13.56

> What would happen if we defined sorted as:

```c++
Foo Foo::sorted() const & {
  Foo ret(*this);
  return ret.sorted();
}
```

It will be infinite loop;

## 13.57

> What if defined sorted as :

```c++
Foo Foo::sorted() const & {
  return Foo(*this).sorted();
}
```

Ok, it's fine.

## 13.58

> Write versions of class Foo with print statements in their sorted functions to test your answers to the previous two exercises.

[code](./exercise13_58.cpp)

