# C++14
Mainly complements and fixes the C++11 stadard
## Binary Literals
Values are represented by literals.
1. decimal
2. hexadecimal
3. octal
4. `binary`
```cpp
#include<iostream>
int main(){
    int x = 10; //decimal
    int y = 0xA; //hexadecimal
    int z = 012; //octal
    int b = 0b1010; //binary
}
```
## Digit Seperator
we can separate digits with single quote \` compiler ignores for readable.
```cpp
#include<iostream>
int main(){
    int x = 1'0; //decimal
    int y = 0xA'1; //hexadecimal
    int z = 0'1'2; //octal
    int b = 0b1'01'0; //binary
}
```

## auto for functions
we can deduce the function type based on the return statement value.

```cpp
#include<iostream>
auto myIntFun(){
    return 123;
}
auto myDoubleFun(){
    return 123.456;
}
int main(){
    auto x = myIntFun();
    auto d = myDoubleFun();
}
```

## Generic Lamdas
we can use auto parameter in lambda function. the type of parameter will be deduced from the value supplied to a lambda function.
```cpp
#include<iostream>
int main(){
    auto mylambda = [](auto p)
    {
        std::cout << "Lamda parameter: " << p << '\n';
    };
    mylambda(123);
    mylambda(456.78);
}
/*
amda parameter: 123
Lamda parameter: 456.78
*/
```

## std::make_ptr
Introduces std::make_ptr function for creating unique pointers.
`prefer this function to a raw new operator`
```cpp
#include<iostream>
#include<memory>
class MyClass{
    int x;
    double d;
    public:
        MyClass(int xx, double dd) : x{xx}, d{dd} {};
        void printdata() { std::cout << "x: " << x
                                     << ", d: " << d << '\n'; }
};
int main(){
    auto p = std::make_unique<MyClass>(1, 3.14);
    p->printdata();
}
/*
x: 1, d: 3.14
*/
```
