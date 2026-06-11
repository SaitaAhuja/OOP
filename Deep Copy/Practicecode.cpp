#include <iostream>
#include <string>

using namespace std; // Using standard namespace globally

class Student {
private:
    string name;
    int rollNumber;
    double* gpa; // Pointer to demonstrate deep copy

public:
    // Default Constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        gpa = new double(0.0); // Allocate memory
    }

    // Parameterized Constructor
    Student(string n, int r, double g) {
        name = n;
        rollNumber = r;
        gpa = new double(g); // Allocate memory
    }

    // --- DEEP COPY: Copy Constructor ---
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        // Allocate NEW memory for this object and copy the VALUE
        gpa = new double(*(other.gpa)); 
    }

    // --- DEEP COPY: Copy Assignment Operator ---
    Student& operator=(const Student& other) {
        if (this == &other) return *this; // Self-assignment check

        // Delete existing memory to prevent memory leak
        delete gpa;

        name = other.name;
        rollNumber = other.rollNumber;
        // Allocate NEW memory and copy the VALUE
        gpa = new double(*(other.gpa)); 

        return *this;
    }

    // Destructor to free allocated memory
    ~Student() {
        delete gpa;
    }

    // Method to modify GPA (to prove deep copy works)
    void changeGpa(double newGpa) {
        *gpa = newGpa;
    }

    void display() const {
        cout << "Name: " << name 
             << " | Roll No: " << rollNumber 
             << " | GPA: " << *gpa << " (Address: " << gpa << ")" << endl;
    }
};

int main() {
    const int SIZE = 2;
    Student classroom[SIZE];

    // Populating the array using our parameterized constructor
    classroom[0] = Student("Alice", 101, 3.8);
    classroom[1] = Student("Bob", 102, 3.5);

    cout << "--- Original Classroom Array ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        classroom[i].display();
    }

    // Creating a DEEP COPY of classroom[0]
    cout << "\n--- Creating Deep Copy of Alice ---" << endl;
    Student aliceCopy = classroom[0]; // Triggers the Copy Constructor
    aliceCopy.display();

    // Modifying the copy shouldn't affect the original object
    cout << "\n--- Modifying Alice's Copy's GPA to 4.0 ---" << endl;
    aliceCopy.changeGpa(4.0);

    cout << "Original Alice: "; 
    classroom[0].display(); // Remains 3.8

    cout << "Copied Alice:   "; 
    aliceCopy.display();    // Changes to 4.0

    return 0;
}
