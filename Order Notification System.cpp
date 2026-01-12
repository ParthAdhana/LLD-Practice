#include<iostream>
#include<set>
using namespace std;
class IObserver
{
    public:
    virtual void update(string status)=0;
    virtual ~IObserver()=default;
};
class ISubject
{
    public:
    virtual void attach(IObserver *observer)=0;
    virtual void detach(IObserver *observer)=0;
    virtual void notify()=0;
    virtual ~ISubject()=default;
};
class Order : public ISubject {
    string status;
    set<IObserver*> observers;

public:
    void attach(IObserver* observer) override {
        observers.insert(observer);
    }

    void detach(IObserver* observer) override {
        observers.erase(observer);
    }

    void notify() override {
        for (auto observer : observers) {
            observer->update(status);
        }
    }

    void setStatus(const string& status) {
        this->status = status;
        notify();
    }
};

class EmailService : public IObserver
{
    public :
    void update(string status) override{
        cout<<"Order updated by EMAIL service to state :"<<status<<endl;
    }
};
class SMSService : public IObserver
{
    public :
    void update(string status) override{
        cout<<"Order updated by SMS service to state :"<<status<<endl;
    }
};
int main() {
    EmailService emailService;
    SMSService smsService;

    Order bookOrder;
    bookOrder.attach(&emailService);
    bookOrder.attach(&smsService);

    bookOrder.setStatus("Order Placed");
}