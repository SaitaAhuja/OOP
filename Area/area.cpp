#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual float area() = 0; // pure virtual function
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float area() {
        return length * width;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float area() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Shape* s;  // Base class pointer

    Rectangle r(4, 5);
    Circle c(3);

    // Using base pointer for Rectangle
    s = &r;
    cout << "Rectangle Area: " << s->area() << endl;

    // Using base pointer for Circle
    s = &c;
    cout << "Circle Area: " << s->area() << endl;

    return 0;
}
