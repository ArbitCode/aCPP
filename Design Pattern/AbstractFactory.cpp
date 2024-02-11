#include <iostream>
#include <string>
#include<memory>
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
    string usefulFun() const 
    {
        return "result of ProductA1";
    }
};
class ProductA2 : public IProductA
{
public:
    string usefulFun() const 
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
    string usefulFun() const 
    {
        return "result of ProductB1";
    }
};
class ProductB2 : public IProductB
{
public:
    string usefulFun() const 
    {
        return "result of ProductB2";
    }
};

class IFactory
{
public:
    virtual ~IFactory() {}
    virtual shared_ptr<IProductA> createProductA() const = 0;
    virtual shared_ptr<IProductB> createProductB() const = 0;
};

class Factory1 : public IFactory
{
    shared_ptr<IProductA> createProductA() const 
    {
        return make_shared<ProductA1>();
    }
    shared_ptr<IProductB> createProductB() const 
    {
        return make_shared<ProductB1>();
    }
};

class Factory2 : public IFactory
{
    shared_ptr<IProductA> createProductA() const 
    {
        return make_shared<ProductA2>();
    }
    shared_ptr<IProductB> createProductB() const 
    {
        return make_shared<ProductB2>();
    }
};

void clientCode(shared_ptr<IFactory> factory)
{
    shared_ptr<IProductA> productA = factory->createProductA();
    shared_ptr<IProductB> productB = factory->createProductB();
    cout << productA->usefulFun() << "\n";
    cout << productB->usefulFun() << "\n";
}

int main()
{
    cout << "Factory 1 :\n";
    shared_ptr<IFactory> f1 = make_shared<Factory1>();
    clientCode(f1);

    cout << "Factory 2 :\n";
    shared_ptr<IFactory> f2 = make_shared<Factory2>();
    clientCode(f2);
}
