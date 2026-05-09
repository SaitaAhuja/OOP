#include<iostream>
#include<cstring>
using namespace std;
class employee{
	private:
		int id;
		double salary;
		char* department;
	public:
		employee(int i,double sal,const char* dep){
			id =i;
			salary = sal;
		department = new char[strlen(dep) + 1];
        strcpy(department, dep);
		}
		employee(employee& other){
			id= other.id;
			salary = other.salary;
			//department = other.department;  //shallow copy
			department = new char[strlen(other.department) + 1];
strcpy(department, other.department);
		}
		~employee(){
			delete[] department;
		}
		friend class hr;
};
class hr{
	string name;
	public:
		hr(string nam){
			name = nam;
		}
		void display(employee &e){
			cout<<name<<endl;
			cout<<e.id<<endl;
			cout<<e.salary;
			cout<<e.department;
		}
		void giveraise(employee& e, double percentage){
			e.salary = e.salary + (e.salary * percentage / 100);
		}
};
class manager:public employee{
	int teamsize;
	public:
		manager(int t, int i, double s,const char* dep):employee(i,s,dep){   //const char* must
			teamsize=t;
		}
		
		int getteamsize(){
			return teamsize;
		}
};
int main(){
   employee e1(101, 50000, "IT");
    hr hr1("John Smith");
    
    cout << "=== BEFORE RAISE ===" << endl;
    hr1.display(e1);
    
    hr1.giveraise(e1, 10);
    
    cout << "\n=== AFTER 10% RAISE ===" << endl;
    hr1.display(e1);
    
    // Test manager
    cout << "\n=== MANAGER ===" << endl;
    manager m1(5, 201, 80000, "IT");
    hr1.display(m1);  // HR can access employee part of manager
    cout << "Team Size: " << m1.getteamsize() << endl;
    
    return 0;
}