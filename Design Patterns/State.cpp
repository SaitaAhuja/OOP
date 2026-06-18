#include <iostream>

using namespace std;

class LightSwitch;

class State {
public:
    virtual void press(LightSwitch* sw) = 0;
};

class OffState : public State {
public:
    void press(LightSwitch* sw) override;
};

class OnState : public State {
public:
    void press(LightSwitch* sw) override;
};

class LightSwitch {
private:
    State* current;
public:
    LightSwitch() { current = new OffState(); }
    void setState(State* newState) { current = newState; }
    void press() { current->press(this); }
};

void OffState::press(LightSwitch* sw) {
    cout << "Turning light ON." << endl;
    sw->setState(new OnState());
}

void OnState::press(LightSwitch* sw) {
    cout << "Turning light OFF." << endl;
    sw->setState(new OffState());
}

int main() {
    LightSwitch sw;

    sw.press(); 
    sw.press(); 

    return 0;
}
