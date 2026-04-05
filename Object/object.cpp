#include <iostream>
#include <string>

class Dog {
public:
    std::string name;
    std::string breed;

    Dog(std::string n, std::string b) {
        name = n;
        breed = b;
    }

    void bark() {
        std::cout << name << " says Woof!" << std::endl;
    }
};

int main() {
    Dog dog1("Buddy", "Golden Retriever");
    Dog dog2("Rocky", "Bulldog");

    dog1.bark();
    dog2.bark();

    return 0;
}
