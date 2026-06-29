#include <iostream>

using namespace std;

class Game {
public:
    void play() {
        initialize();
        startPlay();
        endPlay();
    }
    virtual ~Game() = default;

protected:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;
};

class Chess : public Game {
protected:
    void initialize() override { cout << "Chess Board initialized." << endl; }
    void startPlay() override { cout << "Chess Game started. White moves first." << endl; }
    void endPlay() override { cout << "Chess Game ended. Checkmate." << endl; }
};

class Football : public Game {
protected:
    void initialize() override { cout << "Football Field setup complete." << endl; }
    void startPlay() override { cout << "Football Match kicked off." << endl; }
    void endPlay() override { cout << "Football Match finished. Final whistle." << endl; }
};

int main() {
    Game* game;

    Chess chessGame;
    game = &chessGame;
    game->play();

    Football footballGame;
    game = &footballGame;
    game->play();

    return 0;
}
