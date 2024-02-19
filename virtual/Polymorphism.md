# Polymorphism
One object can behave differently based on binded object.
```cpp
//syntax
Base* obj = new Derived(); // obj type is Base* but morphs according to Derived object.
delete obj;
```
1. `Compile Time Polymorphism` : No virtual function in Base class. `i.e.` Method is bonded with object during compile time itself.
2. `Run Time Polymorphism` : There is at least one virtual function in Base class. `i.e.` Method resolved during run-time using vTable and vPointer created by compiler.

## Base Class
object created on stack.
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
};
int main()
{
    Base base = Base();
    //Base base; both way is same
}
/*
Base constructor
Base Destructor
*/
```

## Derived Class
Object created on stack.<br>
`Constructor calls start from inherited class constructor then own constructor`


```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Derived derived;
    derived.show();
}
/*
Base constructor
Derived constructor
Derived
Derived Destructor
Base Destructor
*/
```
## Base class object can not bind with derived class reference!!!
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Derived derived = Base();
    derived.show();
}
/*
Compilation error:
cannot bind base class object of type 'Base' to derived class reference 'const Derived &'
*/
```
## Base class reference can only bind derived class object.
object has created on stack. `SLICING concept is used note last line of output.`
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Base base = Derived();
    base.show();
}
/*
Base constructor
Derived constructor
Derived Destructor
Base Destructor
Base
Base Destructor
*/
```
## Object created on Heap
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Base* obj = new Base();
    obj->show();
    delete obj;
}
/*
Base constructor
Base
Base Destructor
*/
```
## derived class object created on heap
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Derived* obj = new Derived();
    obj->show();
    delete obj;
}
/*
Base constructor
Derived constructor
Derived
Derived Destructor
Base Destructor
*/
```
## Polymorphism 
1. no vTable created since there is no virtual function.
2. there is memory leak since Base class destructor is not virtual.
3. since no vtable created so compile time polymorphism
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Base* obj = new Derived();
    obj->show();
    delete obj;
}
/* Memory Leak */
/*
Base constructor
Derived constructor
Base
Base Destructor
*/
```
## Base class destructor must be virtual
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    virtual ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Base* obj = new Derived();
    obj->show();
    delete obj;
}
/* Memory Leak : Base class Destructor must be virtual */
/*
Base constructor
Derived constructor
Base
Derived Destructor
Base Destructor
*/
```
## Run time Polymorphism
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
    virtual ~Base(){cout << "Base Destructor" << endl;}
    Base() { cout << "Base constructor" << endl; }
    virtual void show(){ cout << "Base" << endl; }
};
class Derived : public Base
{
public:
    ~Derived() { cout << "Derived Destructor" << endl; }
    Derived() { cout << "Derived constructor" << endl; }
    void show(){ cout << "Derived" << endl; }
};
int main()
{
    Base* obj = new Derived();
    obj->show();
    delete obj;
}

/*
Base constructor
Derived constructor
Derived
Derived Destructor
Base Destructor
*/
```
# Diamond problem
```cpp
#include<iostream>
using namespace std;
class Base
{
    public:
        int b;
        ~Base() { cout << "Base Destructor" << endl; }
        Base() { cout << "Base constructor" << endl; }
        void show() { cout << "Base" << endl; }
};
class Derived1 : public Base{
    public:
        int d1;
        ~Derived1() { cout << "Derived1 Destructor" << endl; }
        Derived1() { cout << "Derived1 constructor" << endl; }
        void show() { cout << "Derived1" << endl; }
};
class Derived2 : public Base
{
public:
    int d2;
    ~Derived2() { cout << "Derived2 Destructor" << endl; }
    Derived2() { cout << "Derived2 constructor" << endl; }
    void show(){ cout << "Derived2" << endl; }
};
class Diamond : public Derived1, public Derived2{

public:
    int diamond;
    ~Diamond() { cout << "Diamond Destructor" << endl; }
    Diamond() { cout << "Diamond constructor" << endl; }
    void show() { cout << "Diamond" << endl; }
};
int main()
{
    Base obj =  Diamond(); // ERROR!!!
    obj.show();
}

/*
error: ambiguous conversion from derived class 'const Diamond' to base class 'const Base':
    class Diamond -> Derived1 -> Base
    class Diamond -> Derived2 -> Base
*/
```
## Run time polymorphism
`Diamond problem solved using virtual inheritance.`

```cpp
#include <iostream>
using namespace std;
class Base
{
public:
    int b;
    virtual ~Base() { cout << "Base Destructor" << endl; }
    Base() { cout << "Base constructor" << endl; }
    virtual void show() { cout << "Base" << endl; }
};
class Derived1 : virtual public Base
{
public:
    int d1;
    ~Derived1() { cout << "Derived1 Destructor" << endl; }
    Derived1() { cout << "Derived1 constructor" << endl; }
    void show() { cout << "Derived1" << endl; }
};
class Derived2 : virtual public Base
{
public:
    int d2;
    ~Derived2() { cout << "Derived2 Destructor" << endl; }
    Derived2() { cout << "Derived2 constructor" << endl; }
    void show() { cout << "Derived2" << endl; }
};
class Diamond : public Derived1, public Derived2
{

public:
    int diamond;
    ~Diamond() { cout << "Diamond Destructor" << endl; }
    Diamond() { cout << "Diamond constructor" << endl; }
    void show() { cout << "Diamond" << endl; }
};
int main()
{
    Base* obj = new Diamond();
    obj->show();
    delete obj;
}

/*
Base constructor
Derived1 constructor
Derived2 constructor
Diamond constructor
Diamond
Diamond Destructor
Derived2 Destructor
Derived1 Destructor
Base Destructor
*/
```


`NOTE:`
1. if function is not virtual
   it will execute base class function itself `i.e.` Compile time polymorphism
2. if function is virtual : use `vTable and vPtr`<br>
   it will first find function in derived class, if not found then go upper derived class until base class.
   
# vTable and vPtr
1. vTable is created when a class have at least one virtual function.
2. vTable is mechanism used to implement dynamic polymorphism
3. `Creation of vTable by Compiler:` when a class contains virtual functions, the compiler creates a vTable(virtual function table) for that class. this table contains pointers to virtual functions of the class.
4. `Pointer Adjustment:` Each object of the class that contains virtual functions includes a hidden pointer(known as vPtr) that points to the vTable. This pointer is initialized by the constructor of the class and adjusted during inheritance.
5. `Dynamic Dispatcher:` when you call a virtual function on a base class pointer or reference, the actual function that gets executed is determined at runtime based on the type of the object the pointer or reference pointing to. this is known as dynamic dispatch.
