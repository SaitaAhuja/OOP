#include <iostream>
#include <string>

using namespace std;

class Payment {
protected:
    double amount;

public:
    Payment(double amt) : amount(amt) {}

    void displayReceipt() {
        cout << "Processing generic payment of $" << amount << endl;
    }

    void displayReceipt(string note) {
        cout << "Receipt: $" << amount << " | Note: " << note << endl;
    }

    virtual void processPayment() = 0; 
};

class CreditCard : public Payment {
private:
    string cardNumber;

public:
    CreditCard(double amt, string card) : Payment(amt), cardNumber(card) {}

    void processPayment() override {
        cout << "Charging $" << amount << " to Credit Card: " << cardNumber << endl;
    }
};

class PayPal : public Payment {
private:
    string email;

public:
    PayPal(double amt, string mail) : Payment(amt), email(mail) {}

    void processPayment() override {
        cout << "Redirecting to PayPal for " << email << " to pay $" << amount << endl;
    }
};

int main() {
    Payment* currentPayment;

    CreditCard visa(85.50, "1234-5678-9012");
    PayPal userAccount(42.00, "dev@example.com");

    currentPayment = &visa;
    currentPayment->processPayment();

    currentPayment = &userAccount;
    currentPayment->processPayment();

    userAccount.displayReceipt("Monthly Subscription");

    return 0;
}
