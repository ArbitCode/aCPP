# -std=C++11

## auto keyword
auto keyword which deduces the type of variable based on the variable's initializer.

```cpp
int main(){
  auto myChar = 'c'; // myChar is char type
  auto myInt = 123;
  auto myDouble = 1234.56;
  auto myFloat = 1234.56f
}
``` 
## Range based Loops : `for each element in container`
```cpp
for(type element : container)
```
```cpp
int main(){
  std::vector<int> vec ={1,2,3,4};
  for(auto element : vec){
    std::cout << element <<"\n";
  }
}
```

## initializer lists: {}
Allow us to initialize objects in `unitform way`.<br>
`it prevents narrowing conversions.`
- when initializing object prefer initializer lists {} over old-stype parenthese()
```cpp
#include<iostream>
#include<vector>
int main(){
    int x = (1.34);
    //int x{1.23} Error : does not allow narrowing
    int a{1};
    int b = {1};
    auto c{'c'};
    std::vector<int> v = {1, 2, 3};
    std::cout << x << a << b << c;
}
```
## Move Semantic
refer to Move constructor and Move assignment.
it uses rvalue `some_type&&`. To cast an expression to an rvalue reference, we use std::move function.

## Lamda expression : we uses as predicate.
Lamda expressions are anonymous function objects. they allow us to write `a short code to be used as a standard library function predicate.`
Lamdas have <br>
capture list marked by [] : where we can capture local variable by reference or copy.<br>
parameter list optional ()<br>
and lamda body {}<br>

signature 
```cpp
[/*capture local var by copy or reference*/](/*parameter*/)
{/*lambda body*/}
```

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto counteven = std::count_if(std::begin(vec), std::end(vec), 
    [](int x){ return x % 2 == 0; } //lamda expression
    );
    std::cout << counteven;
}
/*
count_if(iterator begin, iterator end, predicate)
It returns number of elemenet for which predicate is true.
*/
```

## constexpr Specifier
constexpr promises the variable or function can be evaluated during compile time. If the expression can not be evaluated during compile time, the compiler emits an error.
```cpp
#include<iostream>
int main(){
    constexpr int n{123};
    constexpr double d{345.67};
    constexpr double d2 = d;
    int x = 25;
    constexpr int n2 = x; // compile time error the value of x is not known during compile time.
}
```
## Scoped Enum
unlike the old enum, the scope enum does not leak their names into the surrounding.
```cpp
enum class MyEnum{
  myFirstVal,
  mySecondVal,
  myThirdVal
};
int main(){
  MyEnum myenum = MyEnum::myFirstVal;
}
```
## Smart Pointers
std::unique_ptr<Type> : only one pointer pointing at object.
std::shared_ptr<Type> : multiple shared pointer pointing at object. 

```cpp
#include<iostream>
#include<memory>
#include<utility>
int main(){
    std::unique_ptr<int> pInt = std::make_unique<int>(123);
    std::cout << *pInt;
    //auto pint2 = pInt; // can not be copied
    auto pInt2 = std::move(pInt);
    // std::cout << *pInt; // pInt is nullptr since moved to pInt2
    std::cout << *pInt2;
    std::shared_ptr<int> pSInt = std::make_shared<int>(345);
    auto pSInt1 = std::make_shared<int>(456);
    auto pSInt2 = pSInt; // can be copied
    auto pSInt3 = std::move(pSInt2); // can be moved

    //std::cout << *pSInt2; // pSInt2 is nullptr since moved to pSInt3
    std::cout << *pSInt3;
    std::cout << *pSInt;
    std::cout << sizeof(*pSInt1); // 4 size of int
}
```
## std::unordered_set
std::unordered_set is a container that allows for constant time insertion, searching, and removal of elemenet. the object are not sorted but unique.
```cpp
#include<iostream>
#include<unordered_set>
int main(){
    std::unordered_set<int> myUnorderedSet = {1, 2, 3, 4, -7, 3};
    myUnorderedSet.insert(34);
    myUnorderedSet.insert({2, 3, 4, 5});
    myUnorderedSet.insert({1, 23});
    std::cout << myUnorderedSet.size()
    << "\n";
    for (auto el : myUnorderedSet)
    {
        std::cout << el <<" ";
    }
}
/*
8
23 5 34 -7 4 3 2 1
*/
```
## std::unordered_map
an unordered container of key-value pairs with unique keys.
`“map’s operator [] to insert an element. Normally, this operator is used to access an element value by key. However, if the key does not exist, the operator inserts a new element into the map”`
```cpp
#include<iostream>
#include<unordered_map>
int main(){
    std::unordered_map<char, int> myUnorderedMap = {{'a', 1}, {'b', 2}};
    myUnorderedMap.insert({{'c', 3}, {'d', 4}});
    myUnorderedMap.insert({'f', 5});
    std::cout<< "b " << myUnorderedMap['k'] << '\n'; // key k does not exist, insert new element.
    myUnorderedMap['b'] = 60; // key exist, change the value
    std::cout << "b " << myUnorderedMap['b'] << '\n';

    for (auto el : myUnorderedMap)
    {
        std::cout << el.first << ' ' << el.second << '\n';
    }
}
/*
b 0
b 60
k 0
f 5
d 4
c 3
b 60
a 1
*/
```
## std::tuple
while std::pair can hold two values, the std::tuple can hold more than two values.<br>
To access a certain tuple elemenet<br>
`std::get<index_of_an_element>(tuple_name)`
```cpp
#include<iostream>
#include<utility>
#include<tuple>
int main(){
    std::tuple<int, char, double> myTuple = {1, 'a', 3.14};
    std::cout << "The first element is: " << std::get<0>(myTuple) << '\n';
    std::cout << "The first element is: " << std::get<2>(myTuple) << '\n';

    auto tuple = std::make_tuple<int, double, std::string>(123, 3.14, "Hello_world");
    std::cout << std::get<2>(tuple) << '\n';
}
/*
The first element is: 1
The first element is: 3.14
Hello_world
*/
```

## static_assert
check static(constexpr) condition during compile time.
```cpp
#include<iostream>
#include<cassert>
int main(){
    constexpr int x = 123;
    static_assert(x == 456, "the constexpr value is not 456.");
}
```
## Introduction to Concurrency
`To enable threading, we need to add -pthread flags`
```cpp
g++ -std=c++11 -Wall -pthread source.cpp
```
Running program is called a `process`.<br>
Each process has its own memory and its own address space.<br>
within a process, there can be multiple threads.<br>
`what are threads or threads of execution?`<br>
They are OS mechanism that allows us to execute multiple pieces of code Concurrently/simultaneously.<br>
A process can spawn one or more threads.<br>
Thread share the same memory and thus can communicate with each other using this shared memory.<br>
`To creat a thread object, we use the std::thread class template from a <thread> header file. One defined, the thread starts executing.`
`To create a thread that executes a code inside function, we supply the function name to the thread constructor as a parameter.`
```cpp
#include<iostream>
#include<thread>
#include<string>
void function1(const std::string &param){
    for (int i = 0; i < 5; i++){
        std::cout << "Executing function1 " << param << ": " << i <<"\n";
    }
}
void function2(const std::string &param)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Executing function2 " << param << ": " << i << "\n";
    }
}
int main(){
    std::thread t1{function1, "thread t1 "};
    std::thread t2{function1, "thread t2 "};
    std::thread t3{function2, "thread t3 "};
    t1.join(); // main thread, please wait for me to finish my work before continuing with yours.
    t2.join();
    t3.join();
}
/*
Executing function1 thread t1 : Executing function1 thread t2 : Executing function2 thread t3 : 00
Executing function1 thread t1 : 1
Executing function1 thread t1 : 2
Executing function1 thread t1 : 3
Executing function1 thread t1 : 4

Executing function2 thread t3 : 1
Executing function2 thread t3 : 2
Executing function2 thread t3 : 3
Executing function2 thread t3 : 4
0
Executing function1 thread t2 : 1
Executing function1 thread t2 : 2
Executing function1 thread t2 : 3
Executing function1 thread t2 : 4
*/
```
`There is incosistency in printing output since multiple thread is using same object Concurrently.`<br>
This leads to a problem access std::cout object from two different thread.<b>
this means we need to synchronize the access to a shared std::cout object somehow.<br>
`we do so by locking and unlocking mutexes.`
## Mutexes
`A mutex is a way to synchronize access to shared objects b/w multiple threads.`
A thread owns a mutex once it locks the mutex, then performs access to shared data and unlocks the mutex when access to shared data is no longed needed. this ensures only one thread at a time can have access to shared data.
```cpp
#include<iostream>
#include<thread>
#include<string>
#include<mutex>
std::mutex m;
void function1(const std::string &param)
{
    for (int i = 0; i < 5; i++){
        m.lock();
        std::cout << "Executing function1 " << param << ": " << i << "\n";
        m.unlock();
    }
}
void function2(const std::string &param)
{
    for (int i = 0; i < 5; i++)
    {
        m.lock();
        std::cout << "Executing function2 " << param << ": " << i << "\n";
        m.unlock();
    }
}
int main(){
    std::thread t1{function1, "thread t1 "};
    std::thread t2{function1, "thread t2 "};
    std::thread t3{function2, "thread t3 "};
    t2.join();
    t1.join(); // main thread, please wait for me to finish my work before continuing with yours.
    t3.join();
}
/*
Executing function1 thread t1 : 0
Executing function1 thread t1 : 1
Executing function1 thread t1 : 2
Executing function1 thread t1 : 3
Executing function1 thread t1 : 4
Executing function1 thread t2 : 0
Executing function1 thread t2 : 1
Executing function1 thread t2 : 2
Executing function1 thread t2 : 3
Executing function1 thread t2 : 4
Executing function2 thread t3 : 0
Executing function2 thread t3 : 1
Executing function2 thread t3 : 2
Executing function2 thread t3 : 3
Executing function2 thread t3 : 4
*/
```
shared object is synchronized using mutex.<br>
since we can forget unlock the mutex manully which leads to thread lock infinitely.<br>
A better approach is to use `std::lock_guard` function instead.<br>
It locks the mutex, and once it goes out of scope, it automatically unlocks the mutex.
```cpp
#include<iostream>
#include<thread>
#include<string>
#include<mutex>
std::mutex m;
void function1(const std::string &param)
{
    for (int i = 0; i < 5; i++){
        std::lock_guard<std::mutex> lg(m);
        std::cout << "Executing function1 " << param << ": " << i << "\n";
    }//lock_guard goes out of scope here and unlock the mutex
}
void function2(const std::string &param)
{
    for (int i = 0; i < 5; i++)
    {
        std::lock_guard<std::mutex> lg(m);
        std::cout << "Executing function2 " << param << ": " << i << "\n";
    }
}
int main(){
    std::thread t1{function1, "thread t1 "};
    std::thread t2{function1, "thread t2 "};
    std::thread t3{function2, "thread t3 "};
    t2.join();
    t1.join(); // main thread, please wait for me to finish my work before continuing with yours.
    t3.join();
}
/*
Executing function1 thread t1 : 0
Executing function1 thread t1 : 1
Executing function1 thread t1 : 2
Executing function1 thread t1 : 3
Executing function1 thread t1 : 4
Executing function1 thread t2 : 0
Executing function1 thread t2 : 1
Executing function1 thread t2 : 2
Executing function1 thread t2 : 3
Executing function1 thread t2 : 4
Executing function2 thread t3 : 0
Executing function2 thread t3 : 1
Executing function2 thread t3 : 2
Executing function2 thread t3 : 3
Executing function2 thread t3 : 4
*/
```

## Deleted and defaulted functions
`=default`Specifier, when used on a member function, means: whatever the language rules, I wnat this default member function to be there.
`=delete` Specifier, if we want to disablea member function from apprearing.
```cpp
#include<iostream>
class MyClass{
    int x;
    public:
        MyClass() = default; // requied since copy constructor disable default constructor;
        MyClass(const MyClass &other) : x{other.x} {}
        MyClass &operator=(const MyClass &other) = delete;
};
int main(){
    MyClass obj1;
    MyClass obj2;
    obj2 = obj1; // ERROR: use of deleted function.
}
```

## Type Aliases
`using my_type_name = existing_type_name;`
```cpp
#include<iostream>
#include<string>
#include<vector>
using MyInt = int;
using MyString = std::string;
using MyVector = std::vector<int>;
using MyIntPtr = int *;
int main()
{
    MyInt x = 123;
    MyString s = "Hello World!";
    MyVector v = {1, 2, 3, 4};
    auto v1 = v;
    MyIntPtr p = &x;
    std::cout << *p;
}
```
