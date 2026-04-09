#include <iostream>
using namespace std;

class complex {
public:
    float real;
    float imag;

    complex() {
        real = 0;
        imag = 0;
    }


    void input() {
        cout << "Enter real: ";
        cin >> real;
        cout << "Enter imaginary: ";
        cin >> imag;
    }

    complex operator+(const complex& obj) const {
        complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }


    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    complex c1, c2, result;

    c1.input();
    c2.input();

    result = c1 + c2;

    cout << "The sum is: ";
    result.display();

    return 0;
}
