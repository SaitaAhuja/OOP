#include <iostream>
#include <string>

using namespace std; // Eliminates the need for std::

// Base Class
class Item {
protected:
    string title;
    string itemId;

public:
    Item(string t, string id) : title(t), itemId(id) {}
    virtual ~Item() = default;
};

// Derived Class (Inheritance)
class Book : public Item {
private:
    string author;
    bool isCheckedOut = false;

public:
    Book(string t, string id, string auth) 
        : Item(t, id), author(auth) {}

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << "OOP: Checked out '" << title << "'\n";
        } else {
            cout << "'" << title << "' is already out.\n";
        }
    }
};

int main() {
    Book book1("Calculus Vol 1", "B01", "Stewart");
    book1.checkOut();
    return 0;
}
