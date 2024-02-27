# C++20
Big leap over C++11
## Modules : -fmodules-ts
`Modules are new C++20 features` which aims to eliminate the need for the sepration of code into header and source files. it increases compilation times.<br>
`Modules are included only once and we do not have to seprate the code into interface and implementation.`<br>
One way is to have a single module file, for example mymodule.cpp, where we provide the entire implementation and export of this function.
```cpp
//MyModule.cpp
export module mymodule;
int myPrivateFunction(){
    return 123;
}
export int myfunction()
{
    return myPrivateFunction();
}
namespace MyModule{
    export int x;
    export int myfunction() { return myPrivateFunction(); }
    int y;
    int myPrivateFunction() { return 1234; }
}
```
```cpp
//source.cpp
import mymodule;
#include<iostream>
int main(){
    int x = myfunction();
    std::cout << x<<"\n";
    std::cout << MyModule::myfunction()<<"\n";
    MyModule::x = 12;
    std::cout << MyModule::x <<"\n";
}
/*
123
123
12
*/
```
`Note:` compile command:<bt>
```
#> g++-13 -std=c++20 -Wall -fmodules-ts  mymodule.cpp c.cpp && ./a.out
```
## Concepts
`if we want our template argument T to satisfy certain rewuirement then we uses Concepts.`<br>
`Signature:`
```cpp
template <typename T>
concept concept_name = requires (T var){requirement_expression;};
```
```cpp
//template argument T be incremental, even or odd.
#include<iostream>
#include <concepts>
template <typename T>
concept MustBeIncremental = requires(T x) { x++; };
template <typename T>
concept SupportsModulo = requires(T x) { x%2; };

template <typename T> requires MustBeIncremental<T> && SupportsModulo<T>
void MyFunction(T x)
{
    std::cout << "The value confirm both: " << x << "\n";
}
int main(){
    MyFunction(123);
    MyFunction('c');
    //MyFunction(345.6); //ERROR: no concept valid
}
```
some of predefined concept in C++20
- std::integral - type should be an intergal type.
- std::boolean - type should be boolean
etc.
## lambda templates
`We can use template syntax in our lambda function.`
```cpp
//Signature
auto mylambda = []<typename T>(T param)
{
  //code
};
```

```cpp
#include<iostream>
#include<vector>
#include<typeinfo>
#include<string>

int main(){
  //lambda template
    auto mylambda = []<typename T>(T param)
    {
        std::cout << typeid(T).name()<< '\n';
    };
    std::vector<int> vec = {1, 2, 3, 4};
    mylambda(vec); //integer
    std::vector<std::string> vecStr = {"R", "A", "J", "A"};
    mylambda(vecStr);
}
```
## [likely] and [unlikely] Attributes
complier optimization.
## ranges
A range is object that refers to a range of elements.
```cpp
#include<iostream>
#include<vector>
#include<ranges>
#include<algorithm>
int main(){
    std::vector<int> vec = {3, 9, 1, 2, 8};
    std::ranges::sort(vec);
    for(auto el : vec){
        std::cout << el << " ";
    }
}
/*
1 2 3 8 9
*/
```
`Ranges` have a feature called adaptors.<br>
one of range adaptors is views.<br>
`views are non-owning.`<br>
`views are lazily executed.` : it means the code from views adaptors will not be executed until we iterate over the result of such views.
```cpp
#include<iostream>
#include<ranges>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> vec = {5, 6, 7, 1, 2, 4};
    auto oddAndGreaterThan2 = vec |
                              std::views::filter([](int x)
                                                 { return x % 2 == 1; }) |
                              std::views::filter([](int x)
                                                 { return x > 2; });
    for(auto el : oddAndGreaterThan2)
    {
        std::cout << el << " ";
    }
}
/*
5 7
*/
```
## coruntines
a function that can be suspended and resumed.
## std::span
## mathematical constants
