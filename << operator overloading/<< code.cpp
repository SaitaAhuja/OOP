#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    Student(int m) {
        marks = m;
    }

    friend ostream& operator<<(ostream& out, Student s) {
        out << "Marks: " << s.marks;
        return out;
    }
};

int main() {
    Student s1(90);
    cout << s1;
}
