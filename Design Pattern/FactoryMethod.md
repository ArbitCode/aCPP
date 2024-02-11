# Factory Method
Provides an interface for creating objects in superclass but allow subclass to
alter the type of objects that will be created.
Suggests:
Replace direct object construction calls with calls to a specific factory method.
Object will be created by factory method and return as products.

```cpp
#include <iostream>
#include<vector>
using namespace std;

class IProduct
{
public:
    virtual ~IProduct() {}
    virtual string operation() const = 0;
};

class ProductA : public IProduct
{
public:
    string operation() const override
    {
        return "result of ProdcutA";
    }
};

class ProductB : public IProduct
{
public:
    string operation() const override
    {
        return "result of ProdcutB";
    }
};

class ICreator
{
public:
    virtual ~ICreator() {}
    virtual IProduct *FactoryMethod() const = 0;
    string someOperation()
    {
        IProduct *product = this->FactoryMethod();
        string result = "Creator: the same creator code has just worked with: " + product->operation();
        delete product;
        return result;
    }
};

class CreatorA : public ICreator
{
    IProduct *FactoryMethod() const override
    {
        return new ProductA();
    }
};

class CreatorB : public ICreator
{
    IProduct *FactoryMethod() const override
    {
        return new ProductB();
    }
};

void clientCode(ICreator *creator)
{
    cout << "I'm client: calls " << creator->someOperation() << endl;
}
// creator type depends on env or configuration
int main()
{
    cout << "------------ APP LAUNCH with creatorA ------------\n";
    ICreator *creator = new CreatorA();
    clientCode(creator);
    cout << "------------ APP LAUNCH with creatorB ------------\n";
    ICreator *creator1 = new CreatorB();
    clientCode(creator1);

    delete creator;
    delete creator1;
    return 0;
}



```
