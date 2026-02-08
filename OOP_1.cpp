#include <iostream>
#include <string>
using namespace std;
class Student{
public:
    string name; 
    string roll_no;
    string semester;
    char section;
};
int main(){
    Student s[4];
    for (int i = 0; i < 4; i++) {
        cout<<"Enter details for Student "<<i + 1<<endl;    
        
		cout<<"Name: ";
        getline(cin>>ws, s[i].name);
        
        cout<<"Roll No: ";
        cin>>s[i].roll_no;
        
        cout<<"Semester: ";
        cin>>s[i].semester;
        
        cout<<"Section: ";
        cin>>s[i].section;
   }

    cout<<"\n Section A Students "<<endl;
    for (int i = 0; i < 4; i++) {
        if (s[i].section == 'A' || s[i].section == 'a') {
            cout<<"Name: "<<s[i].name<<" | Roll: "<<s[i].roll_no<<endl;
        }
    }

    return 0;
}
