#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// --- 1. Flyweight Class (Intrinsic State) ---
class LetterTileFlyweight {
private:
    string charValue;    // e.g., 'A'
    string font;        // "FeatherBold"
    string audioPath;   // Shared asset path
    
public:
    LetterTileFlyweight(string c, string f, string audio) 
        : charValue(c), font(f), audioPath(audio) {
        cout << "[System] Loading heavy assets for: " << charValue << endl;
    }

    // Extrinsic state (x, y, isSelected) is passed here
    void render(int x, int y, bool isSelected) const {
        string status = isSelected ? "[SELECTED]" : "[IDLE]";
        cout << "Tile '" << charValue << "' at (" << x << "," << y 
             << ") using font " << font << " " << status << endl;
    }
};

// --- 2. Flyweight Factory (TilePool) ---
class TilePool {
private:
    // Shared instances stored in a map
    static map<string, LetterTileFlyweight*> tiles;

public:
    static LetterTileFlyweight* getTile(string charVal) {
        // Agar tile already map mein hai, toh wahi return karo
        if (tiles.find(charVal) == tiles.end()) {
            tiles[charVal] = new LetterTileFlyweight(charVal, "Duolingo-Bold.ttf", "assets/audio/" + charVal + ".mp3");
        }
        return tiles[charVal];
    }

    static void cleanup() {
        for (auto const& [key, val] : tiles) {
            delete val;
        }
        tiles.clear();
    }
};

// Map initialization
map<string, LetterTileFlyweight*> TilePool::tiles;

// --- 3. Client (ExerciseRenderer) ---
struct TileContext {
    LetterTileFlyweight* flyweight;
    int x, y;
    bool selected;
};

class ExerciseRenderer {
private:
    vector<TileContext> screenElements;

public:
    void addTile(string c, int x, int y) {
        LetterTileFlyweight* tile = TilePool::getTile(c);
        screenElements.push_back({tile, x, y, false});
    }

    void selectTile(int index) {
        if (index < screenElements.size()) {
            screenElements[index].selected = true;
        }
    }

    void draw() {
        cout << "\n--- Duolingo Screen Rendering ---" << endl;
        for (const auto& item : screenElements) {
            item.flyweight->render(item.x, item.y, item.selected);
        }
    }
};

// --- Main Execution ---
int main() {
    ExerciseRenderer duolingo;

    // Task: Spell "BANANA"
    // 'A' aur 'N' multiple times hain, lekin object ek hi baar banega
    duolingo.addTile("B", 10, 50);
    duolingo.addTile("A", 40, 50);
    duolingo.addTile("N", 70, 50);
    duolingo.addTile("A", 100, 50);
    duolingo.addTile("N", 130, 50);
    duolingo.addTile("A", 160, 50);

    duolingo.draw();

    // User selects the first 'A'
    duolingo.selectTile(1);
    duolingo.draw();

    TilePool::cleanup(); // Memory management
    return 0;
}
