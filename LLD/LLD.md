# LLD
0. [OOPs](#oops)
1. [SOLID principle](#solid-principle)
2. Design Patterns
3. Class Diagram
4. UML
5. Sequence & usecase diagram
6. Test case
7. Multithreading

## OOPs
4 Pillars of OOPs
1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphism

## SOLID principle
- `S` : Single Responsibility Principle
- `O` : Open/Closed Principle
- `L` : Liskov Substitution Principle
- `I` : Interface segmented Principle
- `D` : Dependency Inversion Principle

### `S`: Single Responsibility Principle
 A class should have only one reason to change
 ```cpp
// Not a single responsibility class Invoice so need to refactor
#include <iostream>
using namespace std;

class Marker
{
public:
    string m_name;
    string m_color;
    int m_price;
    int m_year;
    Marker(string name, string color, int price, int year)
    {
        m_name = name;
        m_color = color;
        m_price = price;
        m_year = year;
    }
};

class Invoice
{
private:
    Marker m_marker;
    int m_quantity;

public:
    Invoice(Marker marker, int quantity) : m_marker(marker), m_quantity(quantity)
    {
    }
    int CalculateTotal() const { return m_marker.m_price * m_quantity; } // Reason 1: To change for billing
    void printInvoice() const { std::cout << "Invoice Print" << std::endl; } // Reason 2: change for print
    void saveToDB() const { std::cout << "Save to DB" << std::endl; } // Reason 3: SaveToDB
};

int main()
{
}
```

```cpp
// Refactored code
#include <iostream>
using namespace std;

class Marker
{
public:
    string m_name;
    string m_color;
    int m_price;
    int m_year;
    Marker(string name, string color, int price, int year)
    {
        m_name = name;
        m_color = color;
        m_price = price;
        m_year = year;
    }
};

class Invoice
{
private:
    Marker m_marker;
    int m_quantity;

public:
    Invoice(Marker marker, int quantity) : m_marker(marker), m_quantity(quantity)
    {
    }
    int CalculateTotal() const { return m_marker.m_price * m_quantity; } // Reason 1: To change for billing
    
};
class PrintInvoice {
  private:
    int invoice_no;

  public:
      void printInvoice() const { std::cout << "Invoice Print" << std::endl; } // Reason 1: change for print
};

class InvoiceDAO {
    public:
    void saveToDB() const { std::cout << "Save to DB" << std::endl; } // Reason 1: SaveToDB
};

int main()
{
}
```
#### Advantage:
- Avoid Duplicate Code
- Easy to Maintain
- Easy to Understand
- Flexible Software
- Reduce Complexity

### `O` : Open/Close Principle
Open for Extension but close for modification
```cpp
// not following Open/Close Principle
class InvoiceDAO{ // class should be closed for modification
  private:
  string m_invoiceNo;
  public:
  InvoiceDAO(string invoiceNo) : m_invoiceNo(invoiceNo){}
  void saveToDB(){std::cout << "Save To DB" << "\n";}
  void saveToFile(){std::cout << "Save To File" << "\n";}
}
```
Refactor code by open for Extension(Inherit)
```cpp
class AbstractSave{
  public:
  virtual void save() = 0;
  virtual ~AbstractSave(){}
};
class SaveInvoiceDB : public AbstractSave{
  public:
  void save(){
    // save the invoice to DB
  }
};
class SaveInvoiceFile : public AbstractSave{
  public:
  void save(){
    // save the invoice to File
  }
};
```
### `L` : Liskov Substitution Principle
If class B(`child`) is subtype of class A(`parent`), then we should be able to replace object of A(`parent`) with object of B(`child`)  without breaking the behavior of program.

Note: `subclass should extends the capability of parent class not narrow it down.`

```cpp
// Client code should for all derived class of base class
#include <iostream>
#include <string>
#include<exception>
using namespace std;

class AbstractBike
{
public:
    virtual ~AbstractBike() {}
    virtual void turnOnEngine(){std::cout<<"Abstract Turning on engine"<<endl;}
    virtual void turnOffEngine() { std::cout << "Abstract Turning off engine" << endl; }
    virtual void accelerate() { std::cout << "Abstract accelerate" << endl; }
};

class MoterCycle : public AbstractBike
{
    bool isEngineOn;
    int speed;

public:
    void turnOnEngine()
    {
        std::cout << "Turning on engine of MotorCycle" << std::endl;
        isEngineOn = true;
        speed = 0;
    }
    void turnOffEngine()
    {
        std::cout << "Turning off engine of MotorCycle" << std::endl;
        isEngineOn = false;
        speed = 0;
    }
    void accelerate()
    {
        speed += 10;
        std::cout << "Bike speed: " << speed << std::endl;
    }
};

class BiCycle : public AbstractBike
{
    int speed;

  public:
    BiCycle():speed(0){}
  void turnOnEngine() {
        throw string("Exception: bicycle has no engine");
    }
  void turnOffEngine() {

      throw string("Exception: bicycle has no engine");
    }
    void accelerate()
    {
        speed += 10;
        std::cout << "Cycle speed: " << speed << std::endl;
    }
};

void client(AbstractBike *obj) {
    try {
        obj->turnOnEngine();
        obj->accelerate();
        obj->turnOffEngine();
    } catch(std::string &ex) {
        std::cout << ex; 
    }
}

int main() {
    AbstractBike *motorBike = new MoterCycle();
    AbstractBike *biCycle = new BiCycle();
    client(motorBike);
    client(biCycle);
    delete motorBike;
    delete biCycle;
}
```
### `I` : Interface segmented Principle
Interface should be such that derived class should not implement unnecessary functions they do not need.
i.e. Break interface into another interface
```cpp
// Not following Interface segmented Principle
#include <iostream>
using namespace std;
class IResturentEmplyee
{
  virtual void washDishes() = 0;
  virtual void serveGuest() = 0;
  virtual void cookFood() = 0;
};
class Waiter : public IResturentEmplyee { // why waiter is cooking???
  void washDishes() {}
  void serveGuest() {}
  void cookFood() {}
};
class Chef : public IResturentEmplyee { // why chef is serving guest??
    void washDishes() {}
    void serveGuest() {}
    void cookFood() {}
};

int main(int argc, char **argv) {
  
}
```

Refactor code
```cpp
// Segment Interface
#include <iostream>
using namespace std;
class IWatier {
  virtual void serveGuest() = 0;
};
class IChef {
    virtual void cookFood() = 0;
};
class IHelper {
    virtual void washDishes() = 0;
};
class Waiter : public IWatier { 
  void serveGuest() {}
};
class Chef : public IChef {
    void cookFood() {}
};
```

### `D` : Dependency Inversion
Class should depend on Interface rather than concrete classes
```cpp
// Mackbook class is depending on concrete class
#include <iostream>
using namespace std;
class IKeyboard {};
class WiredKeyboard : public IKeyboard {};
class WirelessKeyboard : public IKeyboard {};
class IMouse {};
class WiredMouse : public IMouse {};
class WirelessMouse : public IMouse {};
class ILaptop {};

class Macbook : public ILaptop{
private:
  WiredKeyboard *m_WiredKeyboard;
  WiredMouse *m_WiredMouse;

  public:
      Macbook(WiredKeyboard *WiredKeyboard, WiredMouse *WiredMouse) : m_WiredKeyboard(WiredKeyboard), m_WiredMouse(WiredMouse) {}
};

```
Always use Interface class reference for object introducing.
```cpp
#include <iostream>
using namespace std;
class IKeyboard {};
class WiredKeyboard : public IKeyboard {};
class WirelessKeyboard : public IKeyboard {};
class IMouse {};
class WiredMouse : public IMouse {};
class WirelessMouse : public IMouse {};
class ILaptop {};

class Macbook : public ILaptop{
private:
  IKeyboard *m_keyboard;
  IMouse *m_mouse;

  public:
      Macbook(IKeyboard *keyboard, IMouse *mouse) : m_keyboard(keyboard), m_mouse(mouse) {}
};
```

 

## Design Patterns

## UML

## Class Diagram

## Sequence & usecase diagram

## Test case

## Multithreading
