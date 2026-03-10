#include<iostream>
#include<string>
#include<vector>
using namespace std;
class student{
	private:
		int rollno;
		string name;
		public:
			student(int r, string n){
				rollno = r;
				name = n;
			}
			int getrollno(){
				return rollno;
			}
			string getname(){
				return name;
			}
};
class teacher{
	private:
		string name;
		int id;
		vector<student*> stu;
	public:
		teacher(string n, int i){
			name = n;
			id = i;
		}
		void addstudent(student* s){
			stu.push_back(s);
		}
		void display(){
			for(student* s: stu){
				cout<<"Name:"<<(*s).getname()<<endl;
				cout<<"ID:"<<(*s).getrollno()<<endl;
			}
		}
};
int main(){
	student s1(01,"Ali");
	student s2(02,"Saita");
	teacher t1("Murk",01);
	t1.addstudent(&s1);
	t1.addstudent(&s2);
	t1.display();
	return 0;
}




