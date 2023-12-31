# C++17
Introduces new language and library features and changes some of language rules.
## Nested namespace
```cpp
namespace MyNameSpace1{
  namespace MyNameSpace2{
    namespace MyNameSpace3{
      //some code
    }
  }
}
```
`it can be rewrrited by in C++17:`
```cpp
namespace MyNameSpace1::MyNameSpace2::MyNameSpace3{
  //some code
}
```
## constexpr lambdas
lambdas can now be constexpr expression, meaning they can be evaluated during compile time.
```cpp
#include<iostream>
int main(){
    constexpr auto mylamnda = [](int x, int y)
    { return x + y; }; //both lambda is same.
    auto mylamnda1 = [](int x, int y) constexpr
    { return x + y; };
    static_assert(mylamnda(10, 20) == 30, "The lambda conditions is not true");
    static_assert(mylamnda1(10, 20) == 30, "The lambda conditions is not true");
}
```
## Structured Bindings
Structured Binding binds the variable names to elemenets of compile-time known expressions, such as array or maps.
```cpp
auto [myVar1, myVar2, myVar3] = some_expression;
```
- by value Structured Binding
```cpp
#include<iostream>
#include<map>
int main(){
    int arr[] = {1, 2, 3, 4};
    auto [myVar1, myVar2, myVar3, myVar4] = arr;
    std::cout << myVar1 << "\n";
    for(auto el : arr){
        std::cout << el << "\t";
    }
}
/*
1
1       2       3       4
*/
```
- by reference Structured Binding
```cpp
#include<iostream>
#include<map>
int main(){
    int arr[] = {1, 2, 3, 4};
    auto& [myVar1, myVar2, myVar3, myVar4] = arr;
    myVar3 = 10;
    std::cout << myVar3 << "\n";
    for (auto el : arr)
    {
        std::cout << el << "\t";
    }
}
/*
10
1       2       10      4
*/
```
## std::filesystem
The `std::filesystem` library allows us to work with files, paths, and folders on our system.
```cpp
#include<iostream>
#include<filesystem>
//check given folder exists
int main(){
    std::filesystem::path folderpath = "/Users/arbitcode/CPP/";
    if(std::filesystem::exists(folderpath)){
        std::cout << "folder path exists.\n";
        for (auto el : std::filesystem::directory_iterator(folderpath)){
            std::cout << el.path() <<"\n";
        }
    }else{
        std::cout << "The path: " << folderpath << "does not exist.\n";
    }
}
/*
folder path exists.
"/Users/arbitcode/CPP/c.cpp"
"/Users/arbitcode/CPP/markdown"
"/Users/arbitcode/CPP/LinkedList"
"/Users/arbitcode/CPP/a.out"
"/Users/arbitcode/CPP/Pointers"
"/Users/arbitcode/CPP/class"
"/Users/arbitcode/CPP/.git"
*/
```
following are some useful function inside std::filesystem
`std::filesystem::create_directory` : for creating a directory<br>
`std::filesystem::copy` : for copying files and directories.<br>
`std::filesystem::remove` : for removing a file or an empty folder.<br>
`std::filesystem::remove_all` : remove_all for removing folders and subfolders.<br>
`std::filesystem::recursive_directory_iterate` : interate files and subfolders recursively.
## std::string_view
`Copying data can be expensive operation in terms of CPU usage.`<br>
`The string_view is a non-owning view of a string or substring.` using this we can parse(`not change`) `string efficiently since it uses Pointers and references.`

```cpp
#include<iostream>
#include<string>
#include<string_view>

int main(){
    std::string str = "Hello world from string view.";
    std::string_view sw(str);
    std::cout << sw <<"\n";
    //use member function on of string_view
    std::cout << sw.substr(0, 5) <<"\n";
}
```
## std::any
the std::any can hold a single value of any type.
`std::any_cast<type>(var) is used to access value.`<br>
std::any_cast will throw an exception if try to convert for example 123 to type double.<br>
`This function performs only type-safe convertions.`

```cpp
#include<iostream>
#include<string>
#include<string_view>
#include<any>

int main(){
    std::any a = 2345.566;
    std::any b = true;
    std::any c = 123;
    std::any s = "Hello World!";
    std::cout << std::any_cast<double>(a) <<"\n";
    if(s.has_value() && s.type()== typeid(const char*)){
        auto value = std::any_cast<const char *>(s);
        std::cout << value <<"\n";
    }
    else{
        std::cout << "s does not contain const char* value";
    }
}
/*
2345.57
Hello World!
*/
```
## std::variant better than union
There is another type of data in C++ called `union`.<br>
A union is a type whose data members of different types occupy the same memory.<br>
Only one data member can be accessed at a time.<br>
size of unione is the size of its largest data member.<br>
We can only access the member that was last written to.<br>
```cpp
//Union
#include<iostream>
union MyUnion{
    char c;
    int x;
    double d;
};
int main()
{
    MyUnion myUnion;
    myUnion.c = 'A';
    std::cout << myUnion.c << "\n";
    std::cout << myUnion.x << "\n"; // undefined behavior at this point.
    myUnion.x = 12;
    std::cout << myUnion.x << "\n"; //12
    std::cout << myUnion.d << "\n"; // undefined behavior
}
```
`C++17` Introduces a new way of working with unions using `std::variant` class template.
```cpp
#include<iostream>
#include<variant>
int main(){
    std::variant<int, double, char> myVariant{123}; //variant now holds int.
    try{
        myVariant = 'a';
        std::cout << std::get<2>(myVariant) << "\n";
        std::cout << std::get<char>(myVariant) <<"\n";
        std::cout << std::get<int>(myVariant); //Exception
    }
    catch(const std::bad_variant_access &ex)
    {
        std::cout << "Exception: " << ex.what() <<"\n";
    }
}
```


