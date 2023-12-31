# Advance
- Template
- Enum
- Namespace
- Conversion
- Exceptions
- Smart Pointers
- I/O Streams
---
## Template
Template are mechanism to support `Generic Programming`
.<br>
- Generic define a function or a class without worrying about what types it accepts.<br>
- we define function and class with Generic type, and when we intantiate them, we use a concrete type.<br>
- we define a template by typing<br>
```cpp
template <typename T>
//rest of our function or class code.
```
### Function Template
```cpp
#include<iostream>
#include<memory>
#include<string>

template <typename T, typename U>
void myFunction(T param, U u){
    std::cout << "The value of param is: " << param << "\n";
    std::cout << "The value of U is: " << u << "\n";
}
class MyClass{
    int x;
    public:
    MyClass(int xx):x{xx}{}
    friend std::ostream& operator<<(std::ostream &os, const MyClass &obj){
        os << obj.x;
        return os;
    }
};
int main()
{
    std::shared_ptr<MyClass> obj = std::make_shared<MyClass>(23);
    myFunction(123, "Raja");
    myFunction<double, int>(123.44, 123);
    myFunction<MyClass, char>(*obj, 'c');
    myFunction<bool, bool>(false, true);
    myFunction('c', 1.23l);
    myFunction("Raja", 23);
}
```
### Class template
```cpp
#include<iostream>
#include<memory>
#include<string>
template <typename T>
class MyClass{
    T x;
    public:
        MyClass(T xx);
        T getValue();
        void someThing();
        template <typename U>
        friend std::ostream& operator<<(std::ostream &os, const MyClass<U> &obj);
};
template <typename T>
MyClass<T>::MyClass(T xx): x{xx}{}
template <typename T>
T MyClass<T>::getValue() { return x; };
template <typename T>
void MyClass<T>::someThing() { std::cout << "something\n";}
template <typename U>
std::ostream& operator<<(std::ostream &os, const MyClass<U> &obj)
{
    os <<"Value of X: " << obj.x;
    return os;
}

int main()
{
    std::unique_ptr<MyClass<int>> obj = std::make_unique<MyClass<int>>(123);
    std::cout << obj->getValue() << "\n";
    auto obj1 = std::make_unique<MyClass<std::string>>("Raja");
    std::cout << obj1->getValue() << "\n";
    auto obj2 = std::make_unique<MyClass<double>>(123.23);
    std::cout << obj2->getValue() << "\n";
    auto obj3 = std::make_unique<MyClass<int>>(123);
    std::cout << *obj3<< "\n";
}
```
### Template Specialization
if we want our template behave differently, only for a specific type, we provide template Specialization.
```cpp
#include<iostream>
template <typename T>
void myFunction(T arg){
    std::cout << "T value: " << arg << "\n";
}
template <>
void myFunction(int xx){
    std::cout << "Template int specialization: " << xx << "\n";
}

template <>
void myFunction(char c)
{
    std::cout << "Template char specialization: " << c << "\n";
}

int main(){
    myFunction("Raja");
    myFunction('c');
    myFunction(123); // specialization
    myFunction(123.f);
}
```
## Enum
enum is type whose values are sybolic, user-defined, named constants called enumerators.<br>
There is two type of Enum<br>
- `Unscoped Enums`<br>
```cpp
#include<iostream>
enum MyEnum
{
    myFirstValue,
    mySecondVaue,
    myThirdValue
};
int main(){
    MyEnum myenum = mySecondVaue;
    myenum = myThirdValue;
    std::cout << myenum << "\n";
}
```
- `Scope Enums`<br>
```cpp
#include<iostream>
enum class MyEnum
{
    myFirstValue = 97,
    mySecondVaue,
    myThirdValue
};
int main(){
    MyEnum myenum = MyEnum::mySecondVaue;
    myenum = MyEnum::myThirdValue;
    std::cout << static_cast<int>(myenum) << "\n";
}
```
## Namespace
namespace is scope with name used to goup c++ code.<br>
Every namespace is a different scope.<br>
```cpp
#include<iostream>
namespace MyNameSpace{
    int x;
    double d;
}
namespace MyNameSpace{
    char c;
    bool b;
}
namespace MySecondNameSpace{
    int x;
    double d;
    char c;
    void printd(){
        std::cout << d << "\n";
    }
}
int main(){
    MyNameSpace::d = 12.3;
    MyNameSpace::b = false;
    MySecondNameSpace::d = 123.45;
    MySecondNameSpace::c = 'c';
    MySecondNameSpace::printd();
    std::cout << MyNameSpace::d << "\n";
}
```
## conversion
- Implicit<br>
Some values can be implicitly converted into each other.<br>
`This is true for all built-in type.`<br>
`Narrowing Conversion:` losing some info during conversion.<br>
```cpp
int main(){
  int myint = 123;
  double mydouble = 456.789;
  myint = mydouble; // the decimal part is lost
}
```
`Integral Promotion:` when smaller integer types such as char or short are used in arithmetic operations, they get promoted/converted to integers.
This conversion happens only in arithmetic operations.
```cpp

#include<iostream>
int main(){
    char a = 10;
    char b = 20;
    auto c = a + b;
    std::cout << c;
}
/*30*/
```
Any built-in type can be converted to boolean.
any value other than zero is true.<br>
A boolean type can be converted to int, true means 1 and false means 0.<br>
A pointer of any type can be converted to void* type. we can not dereference to void* type to do so need to static_cast void* type.
```cpp
#include<iostream>
int main(){
    int x = 123;
    int *pint = &x;
    void *pvoid = pint; //covert from int* to void*
    int *pint2 = static_cast<int *>(pvoid);
    std::cout << *pint2 << "\n";
}
/*123*/
```
Arrays are implicitly converted to pointers.
- Explicit<br>
we can Explicitly convert the value of one type to another.
1. `static_cast<type_to_convert_to>(value_to_convert_from)`<br>
this function converts b/w implicitly conertible types.<br>
this function perform a compile type conversion<br>
```cpp
int main(){
  auto myInteger = static_cast<int>(123.456);
}
```
2. `dynamic_cast<>();`
this function converts pointers of base class to pointers of derived class and vice-versa up the inheritance chain.
`dynamic_cast can only convert b/w related classes inside inheritance change.`
```cpp
#include<iostream>
#include<memory>
class MyBaseClass{
    public:
    virtual ~MyBaseClass(){}
};
class MyDerivedClass : public MyBaseClass{
};
class UnRelatedClass{
};
int main()
{
    MyBaseClass *base = new MyDerivedClass;
    MyDerivedClass *derived = new MyDerivedClass;
    UnRelatedClass *UnRelated = new UnRelatedClass;
    if (dynamic_cast<MyDerivedClass *>(base))
    {
        std::cout << "OK, convertible\n";
    }
    else
    {
        std::cout << "Not convertible\n";
    }
    if(dynamic_cast<MyBaseClass*>(derived))
    {
        std::cout << "OK, convertible\n";
    }
    else
    {
        std::cout << "Not convertible\n";
    }
    if(dynamic_cast<UnRelatedClass*>(base))
    {
        std::cout << "Ok, convertible\n";
    }
    else
    {
        std::cout << "Not convertible\n";
    }
    delete base;
    delete derived;
    delete UnRelated;
}
/*
OK, convertible
OK, convertible
Not convertible
*/
```
3. `reinterpret_cast<>();` : avoid error-prone, no type checking.
## Exception
```cpp
try{
  throw object;
}
catch(type_of_throw_object e){
  // handle exception
}
catch(...){
  //unhandled exception
}
```
## Smart pointer
Smart pointers are pointers that own the object they point to and automatically destroy the object they point to and deallocate the memory once the pointer goes out of scope.
No need to manually delete the object.<br>
Smart pointers are declare in \<memory> header
1. unique_ptr<br> 90%
`unique_ptr can not be copied and holds single ownership`.
```cpp
#include<iostream>
#include<memory>
int main(){
    std::unique_ptr<int> p = std::make_unique<int>(123);
    //std::unique_ptr<int> p1 = p; //compilation issue can not be copied.
    auto p1 = std::move(p);
    std::cout << *p1 << "\n";
}
/*
123
*/
```
2. shared_ptr<br>
`We can have multiple pointers point to a single object.` used in data structure like graph.
```cpp
#include<iostream>
#include<memory>
int main(){
    std::shared_ptr<int> p1 = std::make_shared<int>(123);
    auto p2 = p1;
    auto p3 = p2;
    std::cout << *p3 << "\n";
}
/*
123
*/
```
3. weak_ptr

## I/O streams
We can covert objects to stream of bytes. we can also covert stream of bytes to object.<br>
  There is different kind of I/O stream.
  here we will focus on file and string streams.
### File Streams
we can read from a file, and write to a file.STL offers such funcationality via file streams. those file streams defined into \<fstream>header.
1. std::ifstream - Read from file
2. std::ostream - write to a file
3. std::fstream - Read from and Write to a file
- create a file stream fs and associate it with a file name 'myfile.txt' on disk.read the file line by line.
```cpp
#include<iostream>
#include<fstream>
int main(){
    std::fstream fs("myfile1.txt");
    std::string line;
    while(fs){
        std::getline(fs, line);
        std::cout << line <<"\n";
    }
}
```
- read char by char
```cpp
#include<iostream>
#include<fstream>
#include<string>
int main(){
    std::fstream fs("myfile.txt");
    char c;
    while(fs >> std::noskipws >> c){
        std::cout << c;
    }
}
```

- to write into a file.
```cpp
#include<iostream>
#include<fstream>
#include<string>
int main(){
    std::fstream fs("myoutoutfile.txt", std::ios::out); //overrite file
    std::string s = "Hello world\n";
    fs << s;
    fs << "second line.\n";
    fs << "third line.\n";
}
```
- append to file
```cpp
#include<iostream>
#include<fstream>
#include<string>
int main(){
    std::fstream fs("myoutoutfile.txt", std::ios::app); //append to file
    std::string s = "Hello world\n";
    fs << s;
    fs << "second line.\n";
    fs << "third line.\n";
}
```

### String Streams
similary there is stream that allows to read from and write to a string.

```cpp
#include<iostream>
#include<sstream>
#include<string>
int main(){
    std::string s = "hello World!\n";
    std::stringstream ss{s};
    std::cout << ss.str();
}
```
- To insert data into string stream we use << operator
```cpp
#include<iostream>
#include<sstream>
#include<string>
int main(){
    char c = 'A';
    int x = 123;
    double d = 456.78;
    std::stringstream ss;
    ss << "The char is: " << c << ", int is: " << x << ", and double is: " << d <<"\n";
    std::cout << ss.str();
}
/* The char is: A, int is: 123, and double is: 456.78 */
```
- to output data from a stream into an object we use >> operator
```cpp
#include<iostream>
#include<sstream>
#include<string>
int main(){
    std::string s = "A 123 456.67";
    std::stringstream ss{s};
    char c;
    int x;
    double d;
    ss >> c >> x >> d;
    std::cout << c <<" "<< x << " " << d;
}
```
---
