#include <iostream>
#include <cmath>

// 1. Abstraction & Encapsulation
class Shape {
protected:
    std::string color;

public:
    Shape(std::string c) : color(c) {}

    // Virtual function for Polymorphism
    virtual void draw() {
        std::cout << "Drawing a generic shape in " << color << std::endl;
    }

    // Getter for Encapsulation
    std::string getColor() { return color; }
};

// 2. Inheritance
class Circle : public Shape {
private:
    double radius;

public:
    Circle(std::string c, double r) : Shape(c), radius(r) {}

    // 3. Polymorphism (Overriding the base class method)
    void draw() override {
        std::cout << "Drawing a " << color << " circle with radius " << radius << std::endl;
    }

    double area() {
        return M_PI * radius * radius;
    }
};

int main() {
    // Creating an object of the derived class
    Circle myCircle("Red", 5.0);

    // Using the object
    myCircle.draw();
    std::cout << "Area: " << myCircle.area() << std::endl;

    // Demonstrating Polymorphism via a pointer
    Shape* shapePtr = &myCircle;
    shapePtr->draw(); // Calls Circle's draw(), not Shape's

    return 0;
}
