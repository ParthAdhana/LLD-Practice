#include<iostream>
using namespace std;
class Computer
{
    private:
    string cpu;
    int ram=0;
    int storage=0;
    bool gpu=false;
    bool bluetooth=false;

    public:
    Computer(string cpu,int ram,int storage,bool gpu, bool bluetooth)
    :cpu(cpu),ram(ram),storage(storage),gpu(gpu),bluetooth(bluetooth)
    {
    }
};
class IComputerBuilder
{
    public:
    virtual IComputerBuilder& setRam(int ram)=0;
    virtual IComputerBuilder& setStorage(int storage)=0;
    virtual IComputerBuilder& setGpu(bool gpu)=0;
    virtual IComputerBuilder& setBluetooth(bool bluetooth)=0;
    virtual Computer* build()=0;// return product after build
    virtual ~IComputerBuilder()=default;
};
class GamingComputerBuilder : public IComputerBuilder
{
    private :
    string cpu;
    int ram;
    int storage;
    bool gpu;
    bool bluetooth;

    public:
    GamingComputerBuilder(string cpu): cpu(cpu){};
    IComputerBuilder& setRam(int ram) override{
        this->ram=ram;
        return *this;
    };
    IComputerBuilder& setStorage(int storage) override{
        this->storage=storage;
        return *this;
    }
    IComputerBuilder& setGpu(bool gpu) override{
        this->gpu=gpu;
        return *this;
    }
    IComputerBuilder& setBluetooth(bool bluetooth) override{
        this->bluetooth=bluetooth;
        return *this;
    }
    Computer* build() override{
        return new Computer(cpu,ram,storage,gpu,bluetooth);
    }
};
int main()
{
    Computer* pc = GamingComputerBuilder("Intel i9")
                    .setRam(32)
                    .setStorage(1000)
                    .setGpu(true)
                    .build();
    delete pc;
}