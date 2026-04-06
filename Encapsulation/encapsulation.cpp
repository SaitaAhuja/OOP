#include <iostream>
#include <string>

class BankAccount {
private:
    // Hidden data (Attributes)
    std::string owner;
    double balance;

public:
    // Constructor to initialize data
    BankAccount(std::string name, double initialDeposit) {
        owner = name;
        if (initialDeposit > 0) {
            balance = initialDeposit;
        } else {
            balance = 0;
        }
    }

    // Setter: Controlled way to modify private data
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    // Getter: Controlled way to read private data
    double getBalance() {
        return balance;
    }

    std::string getOwner() {
        return owner;
    }
};

int main() {
    BankAccount myAccount("Alice", 500.0);

    // This would cause a COMPILE ERROR because 'balance' is private:
    // myAccount.balance = 1000000; 

    // Proper way to interact with the object:
    myAccount.deposit(250.50);
    
    std::cout << "Owner: " << myAccount.getOwner() << std::endl;
    std::cout << "Final Balance: $" << myAccount.getBalance() << std::endl;

    return 0;
}
