#include<iostream>
using namespace std;

class Payment {
public:
    virtual void pay() = 0;
};

class JazzCash : public Payment {
public:
    void pay() {
        cout << "Paid via JazzCash\n";
    }
};

class EasyPaisa : public Payment {
public:
    void pay() {
        cout << "Paid via EasyPaisa\n";
    }
};

class Shopping {
    Payment* p;
public:
    void setPayment(Payment* p) {
        this->p = p;
    }

    void checkout() {
        p->pay();
    }
};

int main() {
    Shopping s;

    JazzCash j;
    EasyPaisa e;

    s.setPayment(&j);
    s.checkout();

    s.setPayment(&e);
    s.checkout();

    return 0;
}
