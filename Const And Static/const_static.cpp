#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class student{
	private:
   	char* name;
	const int id;
	float marks;
	static int count;
	public:
		student():id(0){
			name = "";
			marks = 0;
			count ++;
		}
		student(char* n,int i, float m):id(i){
			int id = i;
			float marks = m;
			name = new char[strlen(n)+1];
			strcpy(name , n);
			count++;
		}
		student(student& other):id(other.id){
			marks = other.marks;
			name = new char[strlen(other.name)+1];
			strcpy(name,other.name);
			count++;
		}
		char* getname() const{
		return name;	
		}
		int getid() const{
			return id;
		}
		float getmarks() const{
			return marks;
		}
		void setname(char* n){
			delete[] name;
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}
		
		void setmarks(int m){
			if(m>=0&&m<=100){
				marks=m;
			}
			else{
				cout<<"Invalid Marks"<<endl;
			}
		}
	    static int getcount(){
			return count;
		}
		~student(){
			delete[] name;
		}		
};
int student :: count = 0;
class course{
	private:
	char* coursename;
    const int credits;
	static const int maxstudents = 3;
	vector<student*> listofstudents;
	static int count;
	public:
		course():credits(0){
			coursename = "";
			count ++;
		} 
		course(char* n,int c):credits((c>0&&c<=5)?c:0){
			coursename=new char[strlen(n)+1];
			strcpy(coursename,n);
			count ++;
		}
		course(course& other):credits(other.credits){
			coursename=new char[strlen(other.coursename)+1];
			strcpy(coursename,other.coursename);
			count ++;
		}
		static int getcount(){
			return count;	
		}
		string getname() const{
			return coursename;
		}
		void addstudent(student& s){
			if(listofstudents.size() < maxstudents){
				listofstudents.push_back(&s);
			}
			else{
            cout << "Course full!" << endl;
    }
		}
		void display(){
			 cout << "Course: " << coursename << ", Credits: " << credits 
             << ", Max Students: " << maxstudents << endl;
			for(student* s:listofstudents){
				 cout << "Name: " << s->getname() << ", RollNo: " << s->getid() << ", Marks: " << s->getmarks() << endl;
			}
		}		
};
int course:: count = 0;
int main(){
 const student s1("Ali", 101, 95);
    cout << "Const Student details:" << endl;
    cout << s1.getname() << ", Roll: " << s1.getid() 
         << ", Marks: " << s1.getmarks() << endl;

    // Dynamic allocation of course
    course* c1 = new course("OOP", 4);

    c1->addstudent(const_cast<student&>(s1));

    // Other students
    student s2("Sara", 102, 88);
    student s3("Omar", 103, 92);

    c1->addstudent(s2);
    c1->addstudent(s3);

    // Attempt to add beyond maxStudents
    student s4("Zara", 104, 85);
    c1->addstudent(s4); // Should show "Course full!"

    // Display course details
    c1->display();

    // Test deep copy (copy constructor)
    course* c2 = new course(*c1);
    c2->display();

    // Free memory
    delete c1;
    delete c2;

    return 0;  
}




