#include <iostream>

using namespace std;

class PowerSource {
public:
    virtual void consume() {
        cout << "Consuming generic energy..." << endl;
    }
    virtual ~PowerSource() {}
};

class Scanner {
public:
    void scan() {
        cout << "Scanning surroundings..." << endl;
    }
};

// Multiple Inheritance
class Drone : public PowerSource, public Scanner {
public:
    void consume() override {
        cout << "Drone battery discharging..." << endl;
    }

    void flightCheck() {
        cout << "Rotors spinning at 100%." << endl;
    }

    ~Drone() {
        cout << "Drone grounded and off." << endl;
    }
};

int main() {
    // Stack Object
    Drone myDrone;
    myDrone.flightCheck();
    myDrone.scan();

    // Heap Pointer with Polymorphism
    PowerSource* p = new Drone();
    p->consume();

    delete p;

    return 0;
}
