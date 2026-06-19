#include <iostream>

using namespace std;

class Light {
public:
    void turnOn() { cout << "Light is ON." << endl; }
    void turnOff() { cout << "Light is OFF." << endl; }
};

class Command {
public:
    virtual void execute() = 0;
};

class OnCommand : public Command {
private:
    Light* light;
public:
    OnCommand(Light* l) { light = l; }
    void execute() override { light->turnOn(); }
};

class OffCommand : public Command {
private:
    Light* light;
public:
    OffCommand(Light* l) { light = l; }
    void execute() override { light->turnOff(); }
};

class RemoteControl {
private:
    Command* cmd;
public:
    void setCommand(Command* c) { cmd = c; }
    void pressButton() { cmd->execute(); }
};

int main() {
    Light roomLight;
    RemoteControl remote;

    OnCommand on(&roomLight);
    OffCommand off(&roomLight);

    remote.setCommand(&on);
    remote.pressButton();

    remote.setCommand(&off);
    remote.pressButton();

    return 0;
}
