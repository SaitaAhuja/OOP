#include<iostream>
using namespace std;

class Box {
private:
    int width;
    int height;

public:
    Box() {
        width = 10;
        height = 5;
    }

    // friend function declaration
    friend int area(Box b);
};

// friend function definition (outside class)
int area(Box b) {
    return b.width * b.height;   // private members access
}

int main() {
    Box b1;
    cout << "Area = " << area(b1);
    return 0;
}
