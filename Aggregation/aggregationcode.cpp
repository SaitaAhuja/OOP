#include<iostream>
#include<vector>
using namespace std;
class Teacher{
	private:
		string name;
	public:
		Teacher(string n){
			name = n;
		}
		string getname(){
			return name;
		}
		~Teacher(){
			
		}
};
class Department{
	private:
		string name;
		vector<Teacher*> list; //aggregation ptr based
	public:
		Department(string n){
			name = n;
		}
		void addteacher(Teacher *t){
			list.push_back(t);
		}
		void removeteacher(Teacher *t){
			for(auto it=list.begin();it!=list.end();it++){
			     if(*it == t) {
				  list.erase(it);
                  break;   //milgayaa to loopend no need again
            }
        }
    }
		void display(){
			for(int i=0;i<list.size();i++){
				cout<<"Name: "<<list[i]->getname()<<endl;
			}
		}
//		void display(){
//		for(Teacher* t : list){
//        cout << t->getname();
//      }
//    }
		~Department(){
			
		}		
};
int main(){
	Department d1("Maths");
	
	Teacher t1("saita");
	Teacher t2("Nain");
	Teacher t3("Angel");
	
	d1.addteacher(&t1);
	d1.addteacher(&t2);
	d1.addteacher(&t3);
	d1.removeteacher(&t2);
	d1.display();
	
	return 0;
	
}
