#include <iostream>
#include <string>

// 1. Abstraction: Using an Abstract Base Class
class Shape {
public:
    // Pure virtual function makes this an abstract class
    virtual void draw() const = 0; 
    virtual ~Shape() {} // Virtual destructor is a must for inheritance!
};

// 2. Inheritance: Circle "is-a" Shape
class Circle : public Shape {
private:
    // 3. Encapsulation: Keeping data private
    double radius;

public:
    Circle(double r) : radius(r) {}

    // 4. Polymorphism: Overriding the base class method
    void draw() const override {
        std::cout << "Drawing a Circle with radius: " << radius << std::endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    void draw() const override {
        std::cout << "Drawing a Square with side: " << side << std::endl;
    }
};

int main() {
    // Polymorphism in action: Using base class pointers to derived objects
    Shape* myShape1 = new Circle(5.5);
    Shape* myShape2 = new Square(10.0);

    myShape1->draw();
    myShape2->draw();

    // Clean up
    delete myShape1;
    delete myShape2;

    return 0;
}
