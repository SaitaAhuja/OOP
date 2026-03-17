#include<iostream>
using namespace std;
class person{
	protected:
		string name;
		int cnic;
		int age;
	public:
		person(string n, int c, int a){
			name = n;
			cnic = c;
			age = a;
		}
		void displayperson(){
			cout<<name<<endl;
			cout<<cnic<<endl;
			cout<<age<<endl;
		}
		~person(){
			cout<<"Person Destroyed"<<endl;
		}
			
};
class student: public person{
	private:
		float cgpa;
		int rollno;
		static int total;
	public:
		student(string n, int c, int a,float gpa, int r):person(n,c,a){
		if(gpa>= 0 && gpa <= 4){
			cgpa = gpa;
		}
		 else{
			 	cout << "Invalid" << endl;
            cgpa = 0;
			 }
			rollno = r;
			total ++;
		}
		static int gettotal(){
			return total;
		}
		void displaystudent() const{
			cout<<name<<endl;
			cout<<age<<endl;
			cout<<cnic<<endl;
			cout<<cgpa<<endl;
			cout<<rollno<<endl;
		}
		~student(){
			cout<<"Student Destroyed"<<endl;
		}
};
int student:: total = 0;
class teacher: public person{
	private:
		int id;
		float salary;
		static int totalteachers;
		public:
			teacher(string n, int c, int a,int i, float s):person(n,c,a){
				if(i>0 && s >0){
				id = i;
				salary = s;
			 }
			 else{
			 cout << "Invalid" << endl;
    id = 0;      
    salary = 0;
			 }
			 totalteachers++;
			}
			static int gettotal(){
			return totalteachers;
		}
		void displayteacher() const{
			cout<<name<<endl;
			cout<<age<<endl;
			cout<<cnic<<endl;
			cout<<salary<<endl;
			cout<<id<<endl;
		}
		~teacher(){
			cout<<"teacher Destroyed"<<endl;
		}
	
};
int teacher:: totalteachers = 0;
class ta: public student, public teacher{
	private:
		string taskassigned;
		static int totaltas ;
	public:
			ta(string n, int c, int a,float gpa, int r, int i, float s,string t):student(n,c,a,gpa,r),teacher(n,c,a,i,s){
				taskassigned=t;
			 totaltas++;
			}
			static int gettotal(){
			return totaltas;
		}
		void displayta() const{
		//	cout<<name<<endl;
		//	cout<<age<<endl;
		//	cout<<cnic<<endl; 
			cout<<taskassigned<<endl;
			
		}
		~ta(){
			cout<<"ta Destroyed"<<endl;
		}
};
int ta:: totaltas = 0;
int main(){
	student *s1= new student("Ali",1234, 20,4.0 , 101);
	student* s2 = nullptr;
    float sara_gpa = 5.0;
    if(sara_gpa >= 0 && sara_gpa <= 4)
        s2 = new student("Sara", 3466, 25, sara_gpa, 102);
    else
        cout << "Sara cannot be created — invalid GPA!" << endl;

	
	cout<<student::gettotal()<<endl;
	
	ta ta1("ara",88797,6,3.7,146,500,250000,"crying");
	student s3("Hamood",6890,30,4.0,103);
	teacher t1("Miss",798,35,895,25000);
	s3.displayperson();
	t1.displayperson();
	
	ta ta2("Zara",9088797,67,3.7,145,500,2500,"sleeping");
	ta2.displayta();
	
	cout<<ta::gettotal()<<endl;
	cout<<teacher::gettotal()<<endl;
	cout<<student::gettotal()<<endl;
	
if(s1 != nullptr)
    delete s2;
	if(s2 != nullptr)
    delete s2; 
	return 0;
}
