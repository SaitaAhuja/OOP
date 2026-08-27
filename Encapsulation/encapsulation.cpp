#include <iostream>
#include <string>
using namespace std;
class BankAccount { 
private:
    // Hidden data (Attributes)  
    string owner;
    double balance;
public:
    // Constructor to initialize data
    BankAccount(string name, double initialDeposit) {
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
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    } 
    // Getter: Controlled way to read private data
    double getBalance() {
        return balance;
    }
    string getOwner() {
        return owner;
    }
};
int main() {
    BankAccount myAccount("Alice", 500.0);
    // This would cause a COMPILE ERROR because 'balance' is private:
    // myAccount.balance = 1000000; 
    // Proper way to interact with the object:
    myAccount.deposit(250.50); 
    std::cout << "Owner: " << myAccount.getOwner() << endl;
    std::cout << "Final Balance: $" << myAccount.getBalance() << endl;
    return 0;
}
