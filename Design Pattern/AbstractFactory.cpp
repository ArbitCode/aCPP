#include <iostream>
#include <string>
using namespace std;

class IProductA
{
public:
    virtual ~IProductA() {}
    virtual string usefulFun() const = 0;
};
class ProductA1 : public IProductA
{
public:
    string usefulFun() const override
    {
        return "result of ProductA1";
    }
};
class ProductA2 : public IProductA
{
public:
    string usefulFun() const override
    {
        return "result of ProductA2";
    }
};
class IProductB
{
public:
    virtual ~IProductB() {}
    virtual string usefulFun() const = 0;
};
class ProductB1 : public IProductB
{
public:
    string usefulFun() const override
    {
        return "result of ProductB1";
    }
};
class ProductB2 : public IProductB
{
public:
    string usefulFun() const override
    {
        return "result of ProductB2";
    }
};

class IFactory
{
public:
    virtual ~IFactory() {}
    virtual IProductA *createProductA() const = 0;
    virtual IProductB *createProductB() const = 0;
};

class Factory1 : public IFactory
{
    IProductA *createProductA() const override
    {
        return new ProductA1();
    }
    IProductB *createProductB() const override
    {
        return new ProductB1();
    }
};

class Factory2 : public IFactory
{
    IProductA *createProductA() const override
    {
        return new ProductA2();
    }
    IProductB *createProductB() const override
    {
        return new ProductB2();
    }
};

void clientCode(IFactory *factory)
{
    IProductA *productA = factory->createProductA();
    IProductB *productB = factory->createProductB();
    cout << productA->usefulFun() << "\n";
    cout << productB->usefulFun() << "\n";
}

int main()
{
    cout << "Factory 1 :\n";
    IFactory *f1 = new Factory1();
    clientCode(f1);
    delete f1;

    cout << "Factory 2 :\n";
    IFactory *f2 = new Factory2();
    clientCode(f2);
    delete f2;
}
