#include<iostream>
using namespace std;
class IVehicle{
    public:
    virtual void drive()=0;
    virtual ~IVehicle()=default;
};
class Car :public IVehicle{
    public:
    void drive() override{
        cout<<"Car is driving";
    }
};
class Bike: public IVehicle{
    public:
    void drive() override{
        cout<<"Bike is driving";
    }
};
class IVehicleFactory{
    public:
    virtual IVehicle* CreateVehicle()=0;
    void testDrive()
    {
        IVehicle* vehicle=CreateVehicle();
        vehicle->drive();
        delete vehicle;
    }
    virtual ~IVehicleFactory()=default;
};
class CarFactory : public IVehicleFactory
{
    public:
    IVehicle* CreateVehicle() override{
        return new Car();
    };
};
class BikeFactory: public IVehicleFactory
{
    public:
    IVehicle* CreateVehicle() override{
        return new Bike();
    };
};
int main()
{
    IVehicleFactory* vehicle=new CarFactory();
    vehicle->testDrive();
    delete vehicle;
}