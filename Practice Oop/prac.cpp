#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() { return name; }
    int getAge() { return age; }
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
private:
    string course;
public:
    void setCourse(string c) { course = c; }
    string getCourse() { return course; }
    void display() {
        cout << "Student Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Course: " << course << endl;
    }
};

class Teacher : public Person {
private:
    string subject;
public:
    void setSubject(string s) { subject = s; }
    string getSubject() { return subject; }
    void display() {
        cout << "Teacher Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    Person* p1 = new Student();
    p1->setName("Ahuja");
    p1->setAge(21);
    dynamic_cast<Student*>(p1)->setCourse("C++");
    
    Person* p2 = new Teacher();
    p2->setName("Mr. Khan");
    p2->setAge(45);
    dynamic_cast<Teacher*>(p2)->setSubject("Math");
    
    p1->display();
    cout << endl;
    p2->display();
    
    delete p1;
    delete p2;
    return 0;
}
