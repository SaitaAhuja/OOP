#include <iostream>
#include <string>
#include <vector>

// Abstract Base Class
class Shape {
protected:
    std::string color;

public:
    Shape(std::string c) : color(c) {}

    // Pure Virtual Function (Abstraction)
    // This makes Shape an "Abstract Class" that cannot be instantiated.
    virtual double getArea() const = 0; 

    // Virtual Destructor
    // Crucial when using inheritance to prevent memory leaks!
    virtual ~Shape() {}

    void printColor() const {
        std::cout << "Color: " << color << std::endl;
    }
};

// Derived Class 1: Inheritance
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(std::string c, double w, double h) 
        : Shape(c), width(w), height(h) {}

    // Polymorphism: Implementing the specific area for Rectangle
    double getArea() const override {
        return width * height;
    }
};

// Derived Class 2: Inheritance
class Circle : public Shape {
private:
    double radius;

public:
    Circle(std::string c, double r) : Shape(c), radius(r) {}

    // Polymorphism: Implementing the specific area for Circle
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Using a vector of pointers to demonstrate Polymorphism
    std::vector<Shape*> shapes;

    shapes.push_back(new Rectangle("Red", 5.0, 4.0));
    shapes.push_back(new Circle("Blue", 3.0));

    for (const auto& s : shapes) {
        s->printColor();
        std::cout << "Area: " << s->getArea() << std::endl;
        std::cout << "---" << std::endl;
    }

    // Cleaning up memory (Manual cleanup since we used 'new')
    for (auto s : shapes) {
        delete s;
    }

    return 0;
}
