#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing a Circle ◯" << endl; }
};

class Square : public Shape {
public:
    void draw() override { cout << "Drawing a Square □" << endl; }
};

int main() {
    Shape* myShape;

    myShape = new Circle();
    myShape->draw();

    myShape = new Square();
    myShape->draw();

    delete myShape;
    return 0;
}
