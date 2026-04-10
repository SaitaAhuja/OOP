#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
protected:
    string name;
    int damage;

public:
    Weapon(string n, int d) : name(n), damage(d) {}

    virtual ~Weapon() {
        cout << "Cleaning up " << name << "..." << endl;
    }

    virtual void attack() = 0;

    int operator+(const Weapon& other) {
        return this->damage + other.damage;
    }
};

class Sword : public Weapon {
public:
    Sword() : Weapon("Excalibur", 50) {}

    void attack() override {
        cout << "Slashing with " << name << " for " << damage << " damage!" << endl;
    }
};

class Bow : public Weapon {
public:
    Bow() : Weapon("Longbow", 30) {}

    void attack() override {
        cout << "Firing arrows from " << name << " for " << damage << " damage!" << endl;
    }
};

int main() {
    vector<Weapon*> armory;
    
    armory.push_back(new Sword());
    armory.push_back(new Bow());

    cout << "--- BATTLE START ---" << endl;
    for (Weapon* w : armory) {
        w->attack();
    }

    cout << "\nCombined damage of both weapons: " << (*armory[0] + *armory[1]) << endl;

    cout << "\n--- ARMORY CLEANUP ---" << endl;
    for (Weapon* w : armory) {
        delete w; 
    }

    return 0;
}
