// 设计实现一个食品加工厂
#include <iostream>
using namespace std;

// 工厂模式的优点见：https://blog.csdn.net/fmyzc/article/details/79614944
/*
作者总结的优点有：
    1. 解耦对象的创建与使用过程；
    2. 封装对象的创建过程，减小重复度，因此使用者只管使用就好
作者总结的适应场景有：
    1. 对象创建过程复杂；
    2. 类有很多子类，这些子类容易发生改变
*/
class Fruit{
public:
    virtual ~Fruit() {}
    virtual void eat() = 0;
};
class Vegetable{
public:
    virtual void eat() = 0;
};
class Meat{
public:
    virtual void eat() = 0;
};

class Apple : public Fruit{
public:
    void eat(){
        cout<<"eat apple"<<endl;
    }
};
class Carrot : public Vegetable{
public:
    void eat(){
        cout<<"eat carrots"<<endl;
    }
};
class Rice : public Meat{
public:
    void eat(){
        cout<<"eat rice"<<endl;
    }
};

// 工厂方法实现
template <typename T>
class IFactory{
public:
    virtual T* create() = 0;
    virtual ~IFactory() {}
};

// 按照工厂模式来说，还是每一个都对应有自己的Factory比较好吧，因为这里的create可能不同，工厂模式的其中一个作用就是封装这个create对象的过程，因为有些create过程比较复杂
template <typename T, typename S>
class ConcreteFactory : public IFactory<T>{
public:
    T *create(){
        return new S();
    }
};

int main(){
    IFactory<Fruit> *appleFactory = new ConcreteFactory<Fruit,Apple>();
    Fruit *apple = appleFactory->create();
    apple->eat();

    IFactory<Vegetable> *carrotFactory = new ConcreteFactory<Vegetable,Carrot>();
    Vegetable *carrot = carrotFactory->create();
    carrot->eat();

    IFactory<Meat> *riceFactory = new ConcreteFactory<Meat,Rice>();
    Meat *rice = riceFactory->create();
    rice->eat();

    delete appleFactory;
    delete apple;
    delete carrotFactory;
    delete carrot;
    delete riceFactory;
    delete rice;
}