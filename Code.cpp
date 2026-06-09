#include <iostream>
#include <string>
using namespace std; // Removes the need to write std:: every time

// Base Class
class Teacher {
private:
    string name; // Encapsulation: Hidden from direct external access

public:
    // Constructor
    Teacher(string teacherName) {
        name = teacherName;
    }

    // Getter method to safely access private data
    string getName() {
        return name;
    }

    // Virtual function for Polymorphism
    virtual void teach() {
        cout << name << " is teaching a general lesson." << endl;
    }
};

// Derived Class (Inheritance)
class MathTeacher : public Teacher {
public:
    // Pass the name up to the base Teacher constructor
    MathTeacher(string teacherName) : Teacher(teacherName) {}

    // Overriding the teach method (Polymorphism)
    void teach() override {
        cout << getName() << " is teaching Algebra!" << endl;
    }
};

int main() {
    // 1. Create a regular Teacher object
    Teacher t1("Mr. Smith");
    t1.teach();

    // 2. Create a MathTeacher object (Inheritance & Polymorphism)
    MathTeacher t2("Mrs. Davis");
    t2.teach();

    return 0;
}
