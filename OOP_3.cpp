#include <iostream>
#include <cstring>
using namespace std;
class Employee {
private:
    char* EmployeeName;
    const int EmployeeId; 
public:
    Employee(const char* name, int id) : EmployeeId(id) {
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }
    void setEmployeeName(const char* name) {
        delete[] EmployeeName;
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }
    const char* getEmployeeName() const {
        return EmployeeName;
    }
    int getEmployeeId() const {
        return EmployeeId;
    }
    ~Employee() {
        delete[] EmployeeName;
    }
};
int main() {
    Employee Employee1("Saita", 101);
    Employee Employee2("Humaira", 102);
    Employee Employee3("Sara", 103);

    Employee1.setEmployeeName("Zara Ahmed");
    Employee2.setEmployeeName("Ahmed Raza");

    cout<<"Employee 1: "<<Employee1.getEmployeeName()
         <<", ID: "<<Employee1.getEmployeeId()<<endl;

    cout<<"Employee 2: "<<Employee2.getEmployeeName()
         << ", ID: "<<Employee2.getEmployeeId()<<endl;

    cout<<"Employee 3: "<<Employee3.getEmployeeName()
         <<", ID: "<<Employee3.getEmployeeId()<<endl;

    return 0;
}




