## 设计模式

https://www.liaoxuefeng.com/wiki/1252599548343744/1264742167474528

1. **设计模式**:
   - 常见的设计模式，如单例、工厂、观察者、策略、适配器模式等。

2. **软件工程原则**:
   - SOLID 原则，DRY (Don't Repeat Yourself)。

行为性模式:策略 
结构性模式:适配器 
创建性模式:单例 工厂

观察者模式
工厂模式： 简单工厂模式 工厂方式模式和抽象工厂模式 模板工厂模式
https://zhuanlan.zhihu.com/p/83535678


Observer 模式是一种设计模式，允许对象(观察者)订阅另一个对象(主题)的状态变化，当主题状态变化时，自动通知所有观察者。这在多线程环境中尤为重要，因为状态的改变可能由不同的线程触发。

Observer 定义了对象之间的一对多依赖关系，使得当一个对象(称为“subject”或“observable”)改变状态时，所有依赖它的对象(称为“observers”)都会得到通知并自动更新。下面是使用 C++ 实现的 Observer 设计模式的示例：

首先，定义 Observer 和 Observable 的接口：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Observer 接口声明了更新接口，用于从 subjects 接收更新
class Observer {
public:
    virtual ~Observer() {}
    virtual void Update(const std::string &message_from_subject) = 0;
};

// Subject 接口声明了一系列管理 observers 的方法
class Subject {
public:
    virtual ~Subject() {}
    virtual void Attach(Observer *observer) = 0;
    virtual void Detach(Observer *observer) = 0;
    virtual void Notify() = 0;
};
```

然后，实现具体的 Subject 类，它在状态改变时通知所有的 Observers：

```cpp
// ConcreteSubject 管理观察者的订阅和取消订阅，并通知他们状态改变
class ConcreteSubject : public Subject {
public:
    void Attach(Observer *observer) override {
        list_observer_.push_back(observer);
    }

    void Detach(Observer *observer) override {
        list_observer_.remove(observer);
    }

    void Notify() override {
        std::list<Observer *>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(std::string message = "Empty") {
        this->message_ = message;
        Notify();
    }

    void HowManyObserver() {
        std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
    }

private:
    std::list<Observer *> list_observer_;
    std::string message_;
};
```

最后，实现具体的 Observer 类，它会接收来自 Subject 的更新：

```cpp
// ConcreteObserver 每次收到更新消息时都会打印输出
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(Subject &subject) : subject_(subject) {
        this->subject_.Attach(this);
        std::cout << "Hi, I'm the Observer \"" << ++ConcreteObserver::static_number_ << "\".\n";
        this->number_ = ConcreteObserver::static_number_;
    }

    virtual ~ConcreteObserver() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const std::string &message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }

    void RemoveMeFromTheList() {
        subject_.Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }

    void PrintInfo() {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number_;
};

int ConcreteObserver::static_number_ = 0;

void ClientCode() {
    ConcreteSubject *subject = new ConcreteSubject;
    ConcreteObserver *observer1 = new ConcreteObserver(*subject);
    ConcreteObserver *observer2 = new ConcreteObserver(*subject);
    ConcreteObserver *observer3 = new ConcreteObserver(*subject);
    ConcreteObserver *observer4;
    ConcreteObserver *observer5;

    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new ConcreteObserver(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new ConcreteObserver(*subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;
}

int main() {
    ClientCode();
    return 0;
}
```

在这个例子中，`ConcreteSubject` 类是一个具体的被观察

对象，它维护一个 Observer 列表并在状态改变时通知它们。`ConcreteObserver` 类是一个具体的观察者，它实现了 `Update` 方法来接收来自 Subject 的消息。`ClientCode` 函数演示了如何创建 Subject 和多个 Observers，并展示了当 Subject 状态改变时如何通知它们。

Observer 模式广泛用于实现事件处理系统、数据模型与视图的分离(如 MVC 架构)以及发布/订阅系统。
