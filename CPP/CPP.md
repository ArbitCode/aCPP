# CPP
`Application Programming` : Get down to metal where we can perform low-level routines.

## C++ Stantdards
C++ is governed by ISO C++ Standard.
1. C++98
2. C++03
3. C++11
4. C++14
5. C++17
6. C++20
7. C++23
8. C++26

`Every C++ Standard starting from C++11 is known as Modern C++`

## Compilers
1. `g++` as part of `GCC i.e. GNU compiler Collection`
2. `Visual C++` as part of `Visual Studio IDE`
3. `Clang` as part of `LLVM`

## First Program
```cpp
#include<iostream>
int main(){
  //comment
  /*
    @line1
    @line2
  */
 std::cout << "Hello World!";
}
```
`Note: Do not introduce entire std namespace into a corrent scope via
using namespace std; satement.`

## Escape Sequence
the `\` represents an Escape Sequence, a mechanism to represent special character. <br>
new line character `\n` <br>
single quote character `\'`<br>
double character `\"`<br>
a character `\t` <br>

## Types
A type is property defines set of values and operation on those values.<br>
instance of type is called object.<br>
object is a region in memory that has a type, a value, and possibly a name.

## Fundamental Types
1. bool: `1 byte : because RAM has smallest unit of 1 byte`
2. char: `1 byte: -128, 127`
3. int: `4 bytes`
4. float: `4 bytes`
5. double: `8 bytes`
6. std::string: `16 bytes`
7. void

```cpp
#include<iostream>
#include<string>
int main(){
  bool b{true};
  char c = 97; // c = 'c';
  int x{23};
  float f = 12.3f;
  double d = 123.45;
  std::string s = "";
}
```

## Data type Modifier
1. signed - // `default`
2. unsigned - Only positive
3. long - 8 byte
4. short - 2 bytes

## Array
Sequence of same object of same type.

## Pointer
Type that can hold address of perticular object.

```cpp
#include<iostream>
int main(){
  int x = 123;
  int *p = nullptr; // declare pointer
  p = &x;
  std::cout << *p << "\n";
  *p = 345;
  std::cout << *p << "\n";
}
```
## References :  Alias
A reference type is an alias to an existing object in memory. References mnust be initialized.<br>
`const References read-only alias.`
```cpp
#include <iostream>
int main()
{
    int x = 123;
    int &y = x;       // y is reference of x.
    const int &z = x; // z is const reference of x.
    y = 456;
    z = 678; // error read-only reference 'z'
}
```

## auto
the auto Specifier deduces the type of an object based on the object's initializer type.
```cpp
#include<siostream>
int main(){
  int x = 123;
  const auto &y = x;
}
```
## const
C++ uses the const type qualifier to mark the object as `read-only`
## constexpr
It is a const that can be evaluted at `compile time`. `initializer can be evaluted at compile time and must be const expression`.

```cpp
#include<iostream>
int main(){
  const int x; // error, no initializer
  const int y = 12 //OK
  constexpr int n = 123 //OK 123 is const expression at compile time.
  constexpr int z = y //OK y is const
  int a = 12;
  constexpr int p = a // error, the value of x is not known at compile time. or not const.
}

```

## Statement
### Selection Statement
#### if-else Statement
#### Conditional expression
#### Logical Operator
#### Comparision Operator
#### Switch Statement
### Interation Statement
#### for loop
#### while loop
#### do-while loop

## Function
```cpp
type functionName(type arguments){
  statement(s);
  return something;
}
```
### Passing Arguments
3 most used way:

1. Pass by const reference
2. Pass by Reference
3. Pass by Value/Copy
4. Pass by Pointer

```cpp
#include <iostream>
void fun(const int &x)
{
    std::cout << x << "\n"; // x is read-only alias
}
void fun1(int &x)
{
    std::cout << x << "\n"; // x is alias
    x++;
}
void fun2(int *x)
{

    std::cout << *x << "\n"; // x points to
    (*x)++;
}
void fun3(int x)
{
    std::cout << x << "\n"; // x is Copy of
}

int main()
{
    int y = 12;
    fun(y);
    fun1(y);
    fun2(&y);
    fun3(y);
}
```

## literals
Here is some literals and their corresponding types.<br>
c - `char`<br>
123 - `int`<br>
123`u` - `unsigned int`<br>
123`ul` - `unsigned long`<br>
456.23 - `double`<br>
456.23`f` - `float`<br>
true - `bool`<br>
"Hello" - `const char[6]`<br>

## Scope and Lifetime
### Scope : Region of code in which code can be accessed.<br>
Local Scope:<br>
Block Scope:<br>
Global Scope:<br>
```cpp
#include<iostream>
const int GLOBAL_INT = 1; //Global Scope
void fun(){
  int x = 12; //Local Scope
}
int main(){
  int z = 13;
  {
    int z = 12; //block scope
    std::cout << z << "\n"; // 12
  }
    std::cout << z << "\n"; // 13
}
```

### Lifetime : The time an objects spends in memory.
#### Automatic Storage Duration i.e. Stack memery
“memory for an object is automatically allocated at the beginning of a block and deallocated when the code block ends. This is also called stack memory; objects are allocated on the stack”
#### Dynammic Storage Duration i.e. Heap memory
“memory for an object is manually allocated and manually deallocated. This kind of storage is often referred to as heap memory. The user determines when the memory for an object will be allocated and when it will be released. The lifetime of an object is not determined by the scope in which the object was defined”
#### Static Storage Duration i.e. Specifier
“When an object declaration is prepended with a static specifier, it means the storage for a static object is allocated when the program starts and deallocated when the program ends. There is only one instance of such objects, and (with a few exceptions) their lifetime ends when a program ends”

---
