#include <iostream>

class Singleton {
public:
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    static Singleton& get() {
        static Singleton instance;
        return instance;
    }

    void message() {
        std::cout << "Hello from Singleton!" << std::endl;
    }

private:
    Singleton() {} // Private constructor
};

int main() {
    Singleton::get().message();
    return 0;
}
