#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand; // Attribute

    // Method (Class Function)
    void drive() {
        cout << brand << " is driving fast!" << endl;
    }
};

int main() {
    Car myCar;            // 1. Create Object
    myCar.brand = "BMW";  // 2. Set Attribute
    myCar.drive();        // 3. Call Method

    return 0;
}
