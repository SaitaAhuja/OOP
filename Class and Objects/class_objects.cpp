#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    float speed;

public:
    // Constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year  = y;
        speed = 0;
    }

    // Member functions
    void accelerate(float amount) {
        speed += amount;
        cout << brand << " " << model << " accelerates to " << speed << " km/h\n";
    }

    void brake(float amount) {
        speed -= amount;
        if (speed < 0) speed = 0;
        cout << brand << " " << model << " slows down to " << speed << " km/h\n";
    }

    void displayInfo() const {
        cout << "------------------------\n";
        cout << "Brand : " << brand << "\n";
        cout << "Model : " << model << "\n";
        cout << "Year  : " << year  << "\n";
        cout << "Speed : " << speed << " km/h\n";
        cout << "------------------------\n";
    }

    // Destructor
    ~Car() {
        cout << brand << " " << model << " object destroyed.\n";
    }
};

int main() {
    // Creating objects
    Car car1("Toyota", "Corolla", 2022);
    Car car2("Honda",  "Civic",   2023);

    car1.displayInfo();
    car1.accelerate(60);
    car1.accelerate(40);
    car1.brake(30);
    car1.displayInfo();

    cout << "\n";

    car2.displayInfo();
    car2.accelerate(80);
    car2.displayInfo();

    return 0;
}
