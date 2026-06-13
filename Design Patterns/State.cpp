#include <iostream>
using namespace std;

class Fan {
private:
    int state; // 0=Off, 1=Low, 2=High

public:
    Fan() {
        state = 0;
    }

    void pressButton() {
        if (state == 0) {
            state = 1;
            cout << "Fan is on Low Speed\n";
        }
        else if (state == 1) {
            state = 2;
            cout << "Fan is on High Speed\n";
        }
        else {
            state = 0;
            cout << "Fan is Off\n";
        }
    }
};

int main() {
    Fan f;

    f.pressButton();
    f.pressButton();
    f.pressButton();

    return 0;
}
