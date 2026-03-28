#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;

public:
    Shape(std::string c) : color(c) {}
    virtual ~Shape() {}
    virtual double getArea() const = 0;
    
    std::string getColor() const { return color; }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(std::string c, double r) : Shape(c), radius(r) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(std::string c, double w, double h) : Shape(c), width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }
};

int main() {
    Shape* shape1 = new Circle("Red", 5.0);
    Shape* shape2 = new Rectangle("Blue", 4.0, 6.0);

    std::cout << shape1->getColor() << " Circle: " << shape1->getArea() << std::endl;
    std::cout << shape2->getColor() << " Rectangle: " << shape2->getArea() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}
