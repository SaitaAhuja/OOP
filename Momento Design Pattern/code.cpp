#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Memento {
private:
    string state;
public:
    Memento(const string& s) : state(s) {}
    string getState() const { return state; }
};

class TextEditor {
private:
    string content;
public:
    void type(const string& text) { content += text; }
    string getContent() const { return content; }

    Memento save() { return Memento(content); }
    void restore(const Memento& memento) { content = memento.getState(); }
};

class History {
private:
    vector<Memento> history;
public:
    void push(const Memento& m) { history.push_back(m); }
    Memento pop() {
        Memento m = history.back();
        history.pop_back();
        return m;
    }
};

int main() {
    TextEditor editor;
    History history;

    editor.type("Hello ");
    history.push(editor.save()); 

    editor.type("World!");
    cout << "Current: " << editor.getContent() << endl; 

    editor.restore(history.pop()); 
    cout << "After Undo: " << editor.getContent() << endl; 

    return 0;
}
