#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r=0, int i=0) {
        real = r;
        imag = i;
    }

    // operator overloading
    Complex operator + (Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2,3), c2(1,4);

    Complex c3 = c1 + c2;   // operator called
    c3.display();
}
