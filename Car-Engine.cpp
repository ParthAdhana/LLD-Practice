#include<bits/stdc++.h>
using namespace std;
class Wheels
{

};
class Engine
{
    public:
    void starts()
    {
        
    }
    void stops()
    {

    }
};
class Car
{
    private :
    Engine *engine;
    Wheels *wheels[4];
    
    public:
    Car()
    {
        engine= new Engine();
        for(int i=0;i<4;i++)
        wheels[i]=new Wheels();
    }
    void starts()
    {
        engine->starts();
    }
    void stops()
    {
        engine->stops();
    }
};
int main()
{
    Car *car = new Car();
    car->starts();
    car->stops();
}