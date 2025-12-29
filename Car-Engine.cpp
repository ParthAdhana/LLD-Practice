#include<bits/stdc++.h>
using namespace std;
class Wheel
{
    int radius;
    public:
    Wheel(int radius=15): radius(radius){};
};
class Engine {
    bool running = false;
    public:
    void start() {
        running = true;
        cout << "Engine started\n";
    }
    void stop() {
        running = false;
        cout << "Engine stopped\n";
    }
};
class Car {
    Engine engine;
    Wheel wheels[4];

public:
    void start() {
        engine.start();
    }
    void stop() {
        engine.stop();
    }
};
int main()
{
    Car car;
    car.start();
    car.stop();
}