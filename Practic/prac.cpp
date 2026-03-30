#include <iostream>
#include <string>

class SmartDevice {
public:
    std::string name;
    bool isOn = false;

    void pressButton() {
        isOn = !isOn;
        std::clog << name << " is " << (isOn ? "ON" : "OFF") << "\n";
    }
};

class Speaker : public SmartDevice {
public:
    void playMusic() {
        if (isOn) {
            std::cout << "Playing audio...\n";
        } else {
            std::cout << "System offline.\n";
        }
    }
};

int main() {
    Speaker alexa;
    alexa.name = "Living Room";

    alexa.pressButton();
    alexa.playMusic();

    return 0;
}
