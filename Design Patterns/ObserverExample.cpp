#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update() = 0;
};

class Student : public Observer {
public:
    void update() {
        cout << "Student notified\n";
    }
};

class Teacher {
    vector<Observer*> observers;

public:
    void addObserver(Observer* o) {
        observers.push_back(o);
    }

    void notifyAll() {
        for(auto o : observers)
            o->update();
    }
};

int main() {
    Teacher t;
    Student s1, s2;

    t.addObserver(&s1);
    t.addObserver(&s2);

    t.notifyAll();
}
