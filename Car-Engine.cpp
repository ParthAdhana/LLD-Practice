#include<bits/stdc++.h>
using namespace std;
class Wheel
{
    int radius;
    public:
    Wheel(int radius=15): radius(radius){};
};
class IEngine {
    public:
    virtual void start()=0;
    virtual void stop()=0;
    virtual ~IEngine()=default;
};
class PetrolEngine : public IEngine
{
    bool running = false;
    public:
    void start() override {
        running = true;
        cout << "Petrol Engine started\n";
    }
    void stop() override{
        running = false;
        cout << "Petrol Engine stopped\n";
    }
};
class DieselEngine : public IEngine
{
    bool running = false;
    public:
    void start() override {
        running = true;
        cout << "Diesel Engine started\n";
    }
    void stop() override{
        running = false;
        cout << "Diesel Engine stopped\n";
    }
};
class Car {
    IEngine &engine;
    Wheel wheels[4];

public:
    Car(IEngine &engine): engine(engine){}
    void start() {
        engine.start();
    }
    void stop() {
        engine.stop();
    }
};
int main()
{
    PetrolEngine petrolEngine;
    Car car(petrolEngine);
    car.start();
    car.stop();
}