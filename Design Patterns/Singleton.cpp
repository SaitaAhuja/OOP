#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {   // private constructor
        cout << "Object Created\n";
    }

public:
    static Singleton* getInstance() {
        if (instance == NULL)
            instance = new Singleton();
        return instance;
    }

    void show() {
        cout << "Singleton object used\n";
    }
};

Singleton* Singleton::instance = NULL;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->show();

    Singleton* s2 = Singleton::getInstance();
    s2->show();

    return 0;
}
