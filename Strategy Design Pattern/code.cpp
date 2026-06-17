#include <iostream>
#include <memory>

using namespace std;

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(int amount) = 0;
};

class CreditCard : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card." << endl;
    }
};

class PayPal : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal." << endl;
    }
};

class ShoppingCart {
private:
    unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(unique_ptr<PaymentStrategy> newStrategy) {
        strategy = move(newStrategy);
    }
    void checkout(int amount) {
        if (strategy) {
            strategy->pay(amount);
        }
    }
};

int main() {
    ShoppingCart cart;

    cart.setStrategy(make_unique<CreditCard>());
    cart.checkout(100);

    cart.setStrategy(make_unique<PayPal>());
    cart.checkout(200);

    return 0;
}
