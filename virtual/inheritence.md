# Inheritance
Inheritance is reusability of existing code.
There is `5` types of inheritance

1. Single inheritance
2. multiple inheritance
3. multi-level inheritance
4. Hierarchy inheritance
5. Hybrid inheritance
6. Multi-path inheritance `i.e.` `Diamond Problem`
   
## Single Inheritance
A class is allowed to inherit from only one class
```cpp
// Single Inheritance
class Base {
    ...
};
class Derived : public Base{ // class Derived has a copy of class Base
  ...  
};
```

## Multiple Inheritance
A class can inherit from more than one class.
```cpp
// Multiple Inheritance
class Base1{
    ...
};
class Base2{
    ...
};
class Derived : public Base1, public Base2{
    ...
};
```
## Multilevel Inheritance
A derived class is created from another derived class
```cpp
// Multilevel Inheritance
class Base {
    ...
};
class Derived1 : public Base{
    ...
};
class Derived2 : public Derived1{
    ...
};
```
## Hierarchy Inheritance
More than one derived class is created from single Base class
```cpp
// Hierarchy Inheritance
class A{
    ...
};
class B : public A{
    ...
};
class C : public A{
    ...
};
```
## Hybrid Inheritance
implementation combining more than one type of inheritance
```cpp
// Hybric Inheritance
class Vehicle{
    ...
};
class Fare{
    ...
};
class Car : public vehicle{
    ...
};
class Bus : public vehicle, public Fare{
    ...
};
```
## `Multi-path Inheritance` : Diamond Problem
A derived class with two base classes have one common base class in called multi-path inheritance.
```cpp
// multi-path Inheritance : ERROR : Ambiguity Arises
class A{
    ...
};
class B : public A{
    ...
};
class C : public A{
    ...
};
class D : public B, public C{
    ..
};
```
`There is two ways to resolve ambiguity or solve Diamond problem`

1. Using Scope resolution operator
2. Using virtual base class
   
```cpp
// using Scope resolution operator
#include <iostream>
using namespace std;
class A
{
public:
    int a;
};
class B : public A
{
public:
    int b;
};
class C : public A
{
public:
    int c;
};
class D : public B, public C
{
public:
    int d;
};
int main()
{
    D obj;
    obj.B::a = 10;
    obj.C::a = 20;
    /* Ambiguity : D->B->A, D->C->A which path is correct??*/
    //obj.A::a = 30;
    cout << obj.B::a << "\n" << obj.C::a;
}
/*
10
20
*/
```
2. Using Virtual Base class
```cpp
// Virtual Base class
#include <iostream>
using namespace std;
class A
{
public:
    int a;
};
class B : public virtual A
{
public:
    int b;
};
class C : virtual public A
{
public:
    int c;
};
class D : public B, public C
{
public:
    int d;
};
int main()
{
    D obj;
    obj.a = 10;
    obj.a = 20;
    /* Ambiguity : D->B->A, D->C->A which path is correct??*/
    //obj.A::a = 30;
    cout << obj.B::a << "\n" << obj.C::a;
}
/*
20
20
*/
```
`Using virtual base class, Class D will have only one copy of class A`

