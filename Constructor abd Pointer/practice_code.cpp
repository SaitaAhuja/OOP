#include<iostream>
#include<cstring>
using namespace std;
class student{
	private:
	char* name;
	int rollno;
	float marks;
	public:
		student(char* n,int r,float m){
			name = new char[strlen(n)+1];
			strcpy(name,n);
			rollno=r;
			marks=m;
		}
		student(student& s){
			rollno=s.rollno;
			marks=s.marks;
			name= new char[strlen(s.name)+1];
			strcpy(name,s.name);
		}
		char* getname() const{ 
		 return name;
		}
		int getrollno() const{
			return rollno;
		}
		float getmarks() const{
			return marks;
		}
		void setname(char* n){
			delete[] name;
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}
		void setrollno(int r){
			if(r>0&&r<=350){
				rollno = r;
			}
				else{
				cout<<"Invalid"<<endl;
			}
		}
		void setmarks(int m){
			if(m>=0 && m <= 100){
				marks = m;
			}
			else{
				cout<<"Invalid"<<endl;
			}
		}
		void display() const {
        cout << "Name: " << name << ", Roll: " << rollno << ", Marks: " << marks << endl;
    }
		~student(){
			delete[] name;
		}
};
int main(){
 student* s1= new student("Ali",1,90);
 student* s2= new student(*s1);
 
 s1->setname("Saita");
 s1->display();
 s2->display();

    delete s1;
    delete s2;

	return 0;
}
		
		
		
		

