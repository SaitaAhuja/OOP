#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;

public:
    // Constructor
    Person(string n) {
        name = n;
    }

    // Virtual function (for polymorphism)
    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

// Derived class
class Student : public Person {
private:
    int marks;

public:
    // Constructor
    Student(string n, int m) : Person(n) {
        marks = m;
    }

    // Function overriding
    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    // Object of base class
    Person p1("Ali");
    
    // Object of derived class
    Student s1("Ahmed", 90);

    // Base class pointer (polymorphism)
    Person* ptr;

    ptr = &p1;
    ptr->display();

    ptr = &s1;
    ptr->display();

    return 0;
}
