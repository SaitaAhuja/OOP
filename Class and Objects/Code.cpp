#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;

public:
    Vehicle(string b) : brand(b) {}
    virtual void startEngine() = 0; 
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int speed;

public:
    Car(string b, int initialSpeed) : Vehicle(b), speed(initialSpeed) {}

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int s) {
        if (s >= 0) {
            speed = s;
        } else {
            cout << "Speed cannot be negative!" << endl;
        }
    }

    void startEngine() override {
        cout << "The " << brand << " car engine roars to life!" << endl;
    }
};

int main() {
    Car myCar("Toyota", 60);

    myCar.startEngine();
    cout << "Current Speed: " << myCar.getSpeed() << " km/h" << endl;

    myCar.setSpeed(80);
    cout << "Updated Speed: " << myCar.getSpeed() << " km/h" << endl;

    Vehicle* polyVehicle = new Car("Tesla", 0);
    polyVehicle->startEngine();

    delete polyVehicle;

    return 0;
}
