#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Shape {
public:
    virtual ~Shape() {} 
    
    virtual void draw() const {
        cout << "Drawing a generic shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle ◯" << endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Square □" << endl;
    }
};

int main() {
    vector<Shape*> shapes;
    
    shapes.push_back(new Circle());
    shapes.push_back(new Square());

    for (Shape* s : shapes) {
        s->draw();
    }

    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
