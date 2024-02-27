# Operators

# Operator overloading

```cpp
#include<iostream>
using namespace std;
class MyClass{
    double real;
    double imaginary;
    public:
    MyClass(){
        real = 0;
        imaginary = 0;
    }
    MyClass(double rl, double imag){
        real = rl;
        imaginary = imag;
    }
    friend ostream& operator<<(ostream &out, MyClass &obj){
        out << obj.real <<" + i" << obj.imaginary <<endl;
        return out;
    }
    MyClass& operator+(MyClass &obj){
        MyClass* temp = new MyClass();
        temp->real = real + obj.real;
        temp->imaginary = imaginary + obj.imaginary;
        return *temp;
    }
    MyClass& operator=(MyClass &obj){
        if(this != &obj){
            real = obj.real;
            imaginary = obj.imaginary;
        }
        return *this;
    }
    
};
int main(){
    MyClass obj1(3.0, 4.6);
    MyClass obj2(2,3);
    cout << obj1 + obj2;
}
```
