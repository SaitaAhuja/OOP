#include <iostream>
#include <string>

using namespace std; 

class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }

    string add(string a, string b) {
        return a + b; 
    }
};

int main() {
    MathOperations math;

    cout << "Integer Addition: " << math.add(5, 10) << endl;
    cout << "String Concatenation: " << math.add("Hello ", "World") << endl;

    return 0;
}
