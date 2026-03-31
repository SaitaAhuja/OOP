#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    string name;

    // Constructor
    Animal(string n) {
        name = n;
    }

    // Function (can be overridden)
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void sound() {
        cout << name << " says: Woof Woof" << endl;
    }
};

// Another derived class
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void sound() {
        cout << name << " says: Meow" << endl;
    }
};

int main() {
    // Object creation
    Animal* a1;
    Dog d1("Buddy");
    Cat c1("Kitty");

    // Polymorphism (base pointer → child object)
    a1 = &d1;
    a1->sound();

    a1 = &c1;
    a1->sound();

    return 0;
}
