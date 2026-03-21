#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    void displayInfo() {
        cout << year << " " << brand << " " << model << endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla", 2024);
    Car car2("Honda", "Civic", 2023);

    car1.displayInfo();
    car2.displayInfo();

    return 0;
}
