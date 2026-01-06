#include <bits/stdc++.h>
using namespace std;

/* ---------- Strategy Abstraction ---------- */
class IPriceStrategy {
public:
    virtual double calculatePrice(double amount) = 0;
    virtual ~IPriceStrategy() = default;
};

/* ---------- Concrete Strategies ---------- */
class NormalPrice : public IPriceStrategy {
public:
    double calculatePrice(double amount) override {
        return amount;
    }
};

class DiscountPrice : public IPriceStrategy {
public:
    double calculatePrice(double amount) override {
        return amount * 0.8;   // 20% discount
    }
};

class SurgePrice : public IPriceStrategy {
public:
    double calculatePrice(double amount) override {
        return amount * 1.2;   // 20% surge
    }
};

/* ---------- Context ---------- */
class Order {
    double amount;
    IPriceStrategy& pricingStrategy;

public:
    Order(double amount, IPriceStrategy& strategy)
        : amount(amount), pricingStrategy(strategy) {}

    double getFinalPrice() {
        return pricingStrategy.calculatePrice(amount);
    }

    void setPricingStrategy(IPriceStrategy& strategy) {
        pricingStrategy = strategy;
    }
};

/* ---------- Engine Abstraction ---------- */
class IEngine {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~IEngine() = default;
};

/* ---------- Concrete Engine ---------- */
class PetrolEngine : public IEngine {
public:
    void start() override {
        cout << "Petrol engine started\n";
    }

    void stop() override {
        cout << "Petrol engine stopped\n";
    }
};

/* ---------- Car (Single Responsibility) ---------- */
class Car {
    IEngine& engine;

public:
    Car(IEngine& engine) : engine(engine) {}

    void start() {
        engine.start();
    }

    void stop() {
        engine.stop();
    }
};

/* ---------- Main ---------- */
int main() {
    // Vehicle behavior
    PetrolEngine engine;
    Car car(engine);
    car.start();
    car.stop();

    // Pricing behavior
    DiscountPrice discount;
    Order order(3000, discount);
    cout << "Final price (discount): " << order.getFinalPrice() << endl;

    SurgePrice surge;
    order.setPricingStrategy(surge);
    cout << "Final price (surge): " << order.getFinalPrice() << endl;

    return 0;
}
