#include <iostream>

using namespace std;

class Amplifier {
public:
    void turnOn() { cout << "Amplifier turned on." << endl; }
    void setVolume(int level) { cout << "Volume set to " << level << "." << endl; }
};

class Projector {
public:
    void turnOn() { cout << "Projector turned on." << endl; }
    void setInput() { cout << "Projector input set to HDMI." << endl; }
};

class RoomLights {
public:
    void dim() { cout << "Lights dimmed to 20%." << endl; }
};

class HomeTheaterFacade {
private:
    Amplifier amp;
    Projector proj;
    RoomLights lights;

public:
    void watchMovie() {
        cout << "Preparing theater to watch a movie..." << endl;
        lights.dim();
        proj.turnOn();
        proj.setInput();
        amp.turnOn();
        amp.setVolume(10);
        cout << "Movie is now playing!" << endl;
    }
};

int main() {
    HomeTheaterFacade theater;
    theater.watchMovie();
    return 0;
}
